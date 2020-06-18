//
// Created by migue on 19/01/2020.
//

#ifndef ANDROID_PROJECT_COLLISION_HANDLER_H
#define ANDROID_PROJECT_COLLISION_HANDLER_H

#define MAX_SUSCRIBERS 10

#include "../../box2d/include/box2d/box2d.h"
#include <functional>

class Collision_Handler:public b2ContactListener{
    unsigned int number_of_suscribers;
    std::function<void(b2Contact*)> collision_events[MAX_SUSCRIBERS];
    unsigned int          collision_ids[MAX_SUSCRIBERS];

    virtual void BeginContact(b2Contact* contact) override ;
    virtual void EndContact(b2Contact* contact) override ;


public:
    Collision_Handler();
    void execute_events(b2Contact *contact);
    void suscribe_to_collision_Event(std::function<void(b2Contact *contact)>& func);
};


#endif //ANDROID_PROJECT_COLLISION_HANDLER_H
