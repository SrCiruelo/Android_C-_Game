//
// Created by migue on 19/01/2020.
//

#ifndef ANDROID_PROJECT_DYNAMIC_TRIGGER_H
#define ANDROID_PROJECT_DYNAMIC_TRIGGER_H

#include "PhysicsObject.h"

class Dynamic_Trigger: public  PhysicsObject{
public:
    Dynamic_Trigger(My_B2_World& world,b2Vec2 box_dimensions,b2Vec2 position,b2Filter collision_mask, unsigned int entity_type);
    void update() override;
};


#endif //ANDROID_PROJECT_DYNAMIC_TRIGGER_H
