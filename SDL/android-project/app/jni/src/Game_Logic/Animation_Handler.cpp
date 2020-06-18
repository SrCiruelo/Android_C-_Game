//
// Created by migue on 26/01/2020.
//

#include "Animation_Handler.h"

Animation_Handler::Animation_Handler(std::function<float(float)> vel_function,float max_vel,float min_vel)
:character_controller{nullptr},number_of_scrollingTex{0},number_of_Obstacles{0},
vel_function{vel_function},max_vel{max_vel},min_vel{min_vel},finished_run{false}
{
    std::function<void()> my_func = [&](){ this->finished_run = true;};
    Event_Handler::get_instance().suscribe_to_DieEvent(my_func);
}

void Animation_Handler::Attach_Obstacle(Obstacle_Controller *obstacle_controller) {
    obstacle_controllers[number_of_Obstacles] = obstacle_controller;
    ++number_of_Obstacles;
}

void Animation_Handler::Attach_ScrollingTex(Scrolling_Texture *scroll_tex, float initial_vel) {
    scrolling_animations[number_of_scrollingTex] = Scroll_Animation(scroll_tex,initial_vel);
    ++number_of_scrollingTex;
}

void Animation_Handler::Attach_Character(Character_Controller *character_controller) {
    this->character_controller = character_controller;
}

void Animation_Handler::update() {


    float sdl_time = SDL_GetTicks()/1000.0f;
    float vel_scale = vel_function(sdl_time);
    vel_scale = (vel_scale>max_vel)? max_vel:vel_scale;
    vel_scale = (vel_scale<min_vel)? min_vel:vel_scale;

    for(int i{0};!finished_run && i<number_of_scrollingTex;++i){
        scrolling_animations[i].scrolling_tex->scroll_left(scrolling_animations[i].initial_vel * vel_scale);
    }

    time_count += sdl_time - last_time;
    other_time += sdl_time- last_time;
    last_time   = sdl_time;
    if(time_count>=0.2){
        for(int i{0};i<number_of_Obstacles;++i){
            obstacle_controllers[i]->update_animation();
        }
        character_controller->update_animation();
        time_count = 0;
    }
}

Scroll_Animation::Scroll_Animation():scrolling_tex{nullptr},initial_vel{0}{}

Scroll_Animation::Scroll_Animation(Scrolling_Texture * scrolling_tex, float initial_vel):
        scrolling_tex{scrolling_tex},initial_vel{initial_vel}
{}