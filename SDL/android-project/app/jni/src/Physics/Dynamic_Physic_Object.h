//
// Created by migue on 18/01/2020.
//

#ifndef ANDROID_PROJECT_DYNAMIC_PHYSIC_OBJECT_H
#define ANDROID_PROJECT_DYNAMIC_PHYSIC_OBJECT_H

#include "PhysicsObject.h"

class Dynamic_Physic_Object: public PhysicsObject {
public:
    Dynamic_Physic_Object(My_B2_World& world,b2Vec2 box_dimensions,b2Vec2 center_position,float density,
            float friction,bool can_rotate,b2Filter collision_mask, unsigned int entity_type);
    void update() override;
};


#endif //ANDROID_PROJECT_DYNAMIC_PHYSIC_OBJECT_H
