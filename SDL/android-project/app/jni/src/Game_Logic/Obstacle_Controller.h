//
// Created by migue on 25/01/2020.
//

#ifndef ANDROID_PROJECT_OBSTACLE_CONTROLLER_H
#define ANDROID_PROJECT_OBSTACLE_CONTROLLER_H

#include "../Physics/My_B2_World.h"
#include "../Rendering/Game_Renderer.h"
#include "../Rendering/Sprite.h"
#include "../Physics/Dynamic_Trigger.h"
#include <string>




class Obstacle_Controller {
    Sprite*          my_sprite;
    Dynamic_Trigger* physic_object;
public:
    Obstacle_Controller(Sprite* sprite,My_B2_World& physics_world,b2Filter obstacle_filter);
    void set_pos(pixel_coord pos);
    void set_vel(pixel_coord vel);
    pixel_coord get_pos();
    pixel_coord get_vel();
    void update();
    void update_animation();
    Sprite& get_sprite();
    ~Obstacle_Controller();
};


#endif //ANDROID_PROJECT_OBSTACLE_CONTROLLER_H
