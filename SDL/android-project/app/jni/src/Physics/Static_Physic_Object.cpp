//
// Created by migue on 25/01/2020.
//

#include "Static_Physic_Object.h"

Static_Physic_Object::Static_Physic_Object(My_B2_World &world, b2Vec2 box_dimensions,
                                           b2Vec2 position, b2Filter collision_mask,
                                           unsigned int entity_type):PhysicsObject(world,entity_type)
{
    my_body = world.Create_Body_Static_Box(box_dimensions,position,collision_mask);
    my_body->SetUserData(this);
}

void Static_Physic_Object::update() {
    PhysicsObject::update();
}