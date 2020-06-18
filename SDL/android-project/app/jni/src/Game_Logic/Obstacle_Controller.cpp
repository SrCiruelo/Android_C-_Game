//
// Created by migue on 25/01/2020.
//

#include "Obstacle_Controller.h"


Obstacle_Controller::Obstacle_Controller(Sprite* sprite,My_B2_World& physics_world,b2Filter obstacle_filter)
:my_sprite{sprite}
{
    if(my_sprite == nullptr){
        //Exception
        return;
    }
    SDL_Rect obstacle_rect = my_sprite->get_rect();
    pixel_coord sprite_size = my_sprite->get_size();
    sprite_size.x = sprite_size.x*9/10;
    sprite_size.y = sprite_size.y*9/10;
    b2Vec2 real_size = physics_world.pixelScale_to_vecScale(sprite_size);

    pixel_coord sprite_pos = my_sprite->get_pos();
    sprite_pos.x -= sprite_size.x/2;
    sprite_pos.y -= sprite_size.y/2;
    b2Vec2 real_pos = physics_world.pixel_to_b2Vec(sprite_pos) ;


    physic_object = new Dynamic_Trigger(physics_world,real_size,real_pos,obstacle_filter,OBSTACLE_ENTITY_TYPE);
    physic_object->AttachSprite(*my_sprite);

}

void Obstacle_Controller::set_pos(pixel_coord pos) {
    physic_object->set_pixel_pos(pos);
}

void Obstacle_Controller::set_vel(pixel_coord vel) {
    physic_object->set_pixel_vel(vel);
}

Obstacle_Controller::~Obstacle_Controller() {
    delete physic_object;
}

void Obstacle_Controller::update() {
    physic_object->update();
}

void Obstacle_Controller::update_animation() {
    my_sprite->step_current_animation();
}

Sprite& Obstacle_Controller::get_sprite() {
    return *my_sprite;
}

pixel_coord Obstacle_Controller::get_pos() {
    return physic_object->get_pixel_pos();
}