//
// Created by migue on 19/01/2020.
//

#include "Dynamic_Trigger.h"


Dynamic_Trigger::Dynamic_Trigger(My_B2_World& world, b2Vec2 box_dimensions, b2Vec2 position,
                                               b2Filter collision_mask, unsigned int entity_type)
                                               :PhysicsObject(world,entity_type) {
    my_body = world.Create_Body_Dynamic_Trigger(box_dimensions,position,collision_mask);
    my_body->SetUserData(this);
}

void Dynamic_Trigger::update() {
    PhysicsObject::update();
}