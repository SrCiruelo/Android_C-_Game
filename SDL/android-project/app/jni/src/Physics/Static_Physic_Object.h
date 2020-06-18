//
// Created by migue on 25/01/2020.
//

#ifndef ANDROID_PROJECT_STATIC_PHYSIC_OBJECT_H
#define ANDROID_PROJECT_STATIC_PHYSIC_OBJECT_H

#include "PhysicsObject.h"

class Static_Physic_Object:PhysicsObject {
public:
    Static_Physic_Object(My_B2_World& world,b2Vec2 box_dimensions,b2Vec2 position,b2Filter collision_mask, unsigned int entity_type);
    void update() override;
};


#endif //ANDROID_PROJECT_STATIC_PHYSIC_OBJECT_H
