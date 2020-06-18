//
// Created by migue on 19/01/2020.
//

#include "Collision_Handler.h"
#include "../Game_Logic/Character_Controller.h"
#include <android/log.h>


//Solo se van a detectar colisiones entre enemigos y personajes por
//lo que no hay que hacer ninguna comprobación
void Collision_Handler::BeginContact(b2Contact *contact) {
    execute_events(contact);
}

void Collision_Handler::execute_events(b2Contact *contact) {
    for(int i{0};i<number_of_suscribers;++i){
        collision_events[i](contact);
    }
}
void Collision_Handler::EndContact(b2Contact *contact) {

}

Collision_Handler::Collision_Handler():number_of_suscribers{0} {}
void Collision_Handler::suscribe_to_collision_Event(std::function<void(b2Contact *contact)> &func) {
    collision_events[number_of_suscribers] = func;
    ++number_of_suscribers;
}