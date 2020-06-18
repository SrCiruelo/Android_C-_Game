//
// Created by migue on 18/01/2020.
//

#ifndef ANDROID_PROJECT_PHYSICSOBJECT_H
#define ANDROID_PROJECT_PHYSICSOBJECT_H


#include "My_B2_World.h"
#include "../Rendering/Sprite.h"

#define TERRAIN_ENTITY_TYPE 0
#define CHARACTER_ENTITY_TYPE 1
#define OBSTACLE_ENTITY_TYPE 2

class PhysicsObject {
protected:
    Sprite*     my_sprite;
    b2Body*     my_body;
    My_B2_World& world;
    unsigned int entity_type;

public:

    PhysicsObject(My_B2_World& world,unsigned int entity_type);
    void AttachSprite(Sprite& sprite);
    virtual void update();
    b2Vec2 get_physical_pos();
    b2Vec2 get_physical_vel();
    void   set_physical_pos(b2Vec2 pos);
    void   set_physical_vel(b2Vec2 vel);
    void   set_pixel_pos   (pixel_coord pos);
    void   set_pixel_vel   (pixel_coord vel);
    pixel_coord   get_pixel_pos   ();
    pixel_coord   get_pixel_vel   ();
    unsigned int get_entity_type();
    b2ContactEdge* Get_Contact_list();


    void    Apply_Force(b2Vec2 force);
    void    Apply_Impulse(b2Vec2 force);
    void    set_gravityScale(float scale);
};


#endif //ANDROID_PROJECT_PHYSICSOBJECT_H
