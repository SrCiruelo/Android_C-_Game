//
// Created by migue on 18/01/2020.
//

#ifndef ANDROID_PROJECT_MY_B2_WORLD_H
#define ANDROID_PROJECT_MY_B2_WORLD_H


#include "../../box2d/include/box2d/box2d.h"
#include "../pixel_coord.h"
#include "Collision_Handler.h"
#include <functional>

constexpr float left_b2_screen_coord   = -10;
constexpr float right_b2_screen_coord  =  10;
constexpr float top_b2_screen_coord    =  10;
constexpr float bottom_b2_screen_coord =  -10;

constexpr float canvas_x_SIZE = right_b2_screen_coord - left_b2_screen_coord;
constexpr float canvas_y_SIZE  = top_b2_screen_coord  - bottom_b2_screen_coord;

class My_B2_World {
    b2World world;
    unsigned int SCREEN_WIDTH;
    unsigned int SCREEN_HEIGHT;
    Collision_Handler collision_handler;
public:
    My_B2_World(b2Vec2 gravity, unsigned int SCREEN_WIDTH,unsigned int SCREEN_HEIGHT);
    My_B2_World(const My_B2_World&) = default;
    b2Body* Create_Body_Dynamic_Box(b2Vec2 box_dimensions,b2Vec2 position,float density,float friction,bool FixedRotation,b2Filter collision_mask);
    b2Body* Create_Body_Static_Box (b2Vec2 box_dimensions,b2Vec2 position,b2Filter collision_mask);
    b2Body* Create_Body_Dynamic_Trigger(b2Vec2 box_dimensions,b2Vec2 position,b2Filter collision_mask);
    void         physics_step(float timeStep,int32 velocityIterations, int32 positionIterations );
    b2Vec2      pixel_to_b2Vec(pixel_coord coord);
    b2Vec2      pixelScale_to_vecScale(pixel_coord size);
    pixel_coord b2Vec_to_pixel(b2Vec2      coord);
    pixel_coord vecScale_to_pixelScale(b2Vec2 size);
    void suscribe_to_collsion_Event(std::function<void(b2Contact *)> my_func);
};




#endif //ANDROID_PROJECT_MY_B2_WORLD_H
