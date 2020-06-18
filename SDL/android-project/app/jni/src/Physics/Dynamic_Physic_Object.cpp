//
// Created by migue on 18/01/2020.
//

#include "Dynamic_Physic_Object.h"


Dynamic_Physic_Object::Dynamic_Physic_Object(My_B2_World& world,b2Vec2 box_dimensions,b2Vec2 center_position
        ,float density,float friction,bool can_rotate,b2Filter collision_mask, unsigned int entity_type)
:PhysicsObject(world,entity_type) {
    my_body = world.Create_Body_Dynamic_Box(box_dimensions,center_position,density,friction,can_rotate,collision_mask);
    my_body->SetUserData(this);
}



void Dynamic_Physic_Object::update() {
    PhysicsObject::update();
}