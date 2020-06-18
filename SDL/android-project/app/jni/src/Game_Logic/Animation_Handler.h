//
// Created by migue on 26/01/2020.
//

#ifndef ANDROID_PROJECT_ANIMATION_HANDLER_H
#define ANDROID_PROJECT_ANIMATION_HANDLER_H

#include "../Rendering/Scrolling_Texture.h"
#include "Character_Controller.h"
#include "Obstacle_Controller.h"
#include <Functional>
#include "Event_Handler.h"

#define MAX_SCROLLING_TEX 10
#define MAX_OBSTACLE      10

struct Scroll_Animation{
    Scrolling_Texture* scrolling_tex;
    float              initial_vel;
    Scroll_Animation();
    Scroll_Animation(Scrolling_Texture* ,float );
    Scroll_Animation( Scroll_Animation& )= default;
    Scroll_Animation( Scroll_Animation&& )= default;
    Scroll_Animation& operator=( Scroll_Animation& ) = default;
    Scroll_Animation& operator=( Scroll_Animation&& ) = default;
};

class Animation_Handler {
    unsigned int number_of_scrollingTex;
    Scroll_Animation   scrolling_animations[MAX_SCROLLING_TEX];
    unsigned int number_of_Obstacles;
    Obstacle_Controller* obstacle_controllers[MAX_OBSTACLE];
    Character_Controller* character_controller;

    bool finished_run;
    std::function<float(float)> vel_function;
    float max_vel;
    float min_vel;
    float time_count;
    float other_time;
    float last_time;
public:
    Animation_Handler(std::function<float(float)>,float max_vel,float min_vel);
    void update();
    void Attach_ScrollingTex(Scrolling_Texture* scroll_tex,float initial_ve);
    void Attach_Obstacle(Obstacle_Controller* obstacle_controller);
    void Attach_Character(Character_Controller* character_controller);

};


#endif //ANDROID_PROJECT_ANIMATION_HANDLER_H
