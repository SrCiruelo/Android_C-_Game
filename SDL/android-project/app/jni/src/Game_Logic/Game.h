//
// Created by migue on 15/01/2020.
//

#ifndef ANDROID_PROJECT_GAME_H
#define ANDROID_PROJECT_GAME_H

#include <SDL_IMAGE.h>
#include <SDL.h>
#include "../Rendering/Game_Renderer.h"
#include "Game_Initializations.h"
#include "../Physics/My_B2_World.h"
#include "../Physics/Collision_Handler.h"

#include "Event_Handler.h"
#include "Obstacle_Handler.h"

class Game{

private:
    SDL_Window*   window;
    SDL_Renderer* renderer;

    Game_Renderer*        game_renderer;
    Game_Initializations* game_init;
    My_B2_World*          physics_world;
    Collision_Handler*    collision_handler;
    Animation_Handler*    animation_handler;
    Obstacle_Handler*     obstacle_handler;

public:

    Game() = delete;
    Game(unsigned int, unsigned int);
    void update();
    void FixedUpdate();
    void Start_Game_Loop();
    void event_handle();
    void render();
    ~Game();
};


#endif //ANDROID_PROJECT_GAME_H
