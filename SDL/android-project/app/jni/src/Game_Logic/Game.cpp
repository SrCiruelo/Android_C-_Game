//
// Created by migue on 15/01/2020.
//

#include "Game.h"
#include <android/log.h>

#include <math.h>
float vel_function(float time){
    return log(time)/log(2.4f);
}
Game::Game(unsigned int SCREEN_HEIGHT,unsigned int SCREEN_WIDTH)
{

    SDL_Init(SDL_INIT_EVERYTHING);          // Initialize SDL2

    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int Width = DM.w;
    int Height = DM.h;

    SCREEN_HEIGHT = Height;
    SCREEN_WIDTH  = Width;
    __android_log_print(ANDROID_LOG_ERROR, "TRACKERS", "%s %d", "Width:",Width);
    __android_log_print(ANDROID_LOG_ERROR, "TRACKERS", "%s %d", "Height:",Height);

    window = SDL_CreateWindow(
            "An SDL2 window",                  // window title
            SDL_WINDOWPOS_UNDEFINED,           // initial x position
            SDL_WINDOWPOS_UNDEFINED,           // initial y position
            SCREEN_WIDTH,                               // width, in pixels
            SCREEN_HEIGHT,                               // height, in pixels
            SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN                  // flags - see below
    );


    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        SDL_Log("Error creating Window");
        SDL_Log("SDL Error: %s", SDL_GetError());
        __android_log_print(ANDROID_LOG_ERROR, "TRACKERS", "%s", "Couldn't Create Window");
    }
    else{
        __android_log_print(ANDROID_LOG_ERROR, "TRACKERS", "%s", "WINDOW WAS CREATED");
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        __android_log_print(ANDROID_LOG_ERROR, "TRACKERS", "%s", "Couldn't Create Renderer");
    }
    else{
        __android_log_print(ANDROID_LOG_ERROR, "TRACKERS", "%s", "RENDERER WAS CREATED");
    }
    game_renderer = new Game_Renderer(renderer);
    b2Vec2 gravity(0,-10.0f);
    physics_world = new My_B2_World(gravity,SCREEN_WIDTH,SCREEN_HEIGHT);
    animation_handler = new Animation_Handler(vel_function,10,1);
    obstacle_handler  = new Obstacle_Handler(game_renderer,vel_function,vel_function);
    game_init     = new Game_Initializations(*animation_handler,*game_renderer,*obstacle_handler,*physics_world);

}


Game::~Game(){
    delete game_renderer;
    delete game_init;
    delete physics_world;
    delete collision_handler;
    delete animation_handler;
    SDL_DestroyWindow(window);
    SDL_Quit();

}
void Game::event_handle() {
    Event_Handler::get_instance().update();
}

void Game::Start_Game_Loop() {

    unsigned int SCREEN_FRAMES = 60;
    unsigned int SCREEN_TICKS_PER_SECOND = 1000/SCREEN_FRAMES;

    Event_Handler::get_instance().start_game();
    while(Event_Handler::get_instance().is_window_running()){
        unsigned int  start_time = SDL_GetTicks();

        event_handle();
        update();
        render();
        //Physics should have their own loop
        FixedUpdate();
        unsigned int  end_time   =  SDL_GetTicks();
        unsigned int  frame_time = (SDL_GetTicks() - start_time);
        if(frame_time<SCREEN_TICKS_PER_SECOND){
            //wait next keyframe if finished early
            SDL_Delay(SCREEN_TICKS_PER_SECOND - frame_time);
        }
    }
}
float time_count = 0;
float last_time = 0;
float other_time = 0;
bool  changed = false;

void Game::update() {
    game_init->player->update();
    obstacle_handler->update();
    animation_handler->update();
}



void Game::FixedUpdate() {
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    physics_world->physics_step(timeStep,velocityIterations,positionIterations);
}


void Game::render() {
    game_renderer->render();
}