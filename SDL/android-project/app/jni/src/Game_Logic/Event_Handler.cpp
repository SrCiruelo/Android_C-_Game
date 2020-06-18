//
// Created by migue on 19/01/2020.
//

#include "Event_Handler.h"
#include <SDL.h>

Event_Handler* Event_Handler::instance = nullptr;

bool Event_Handler::has_started() {
    return is_game_started;
}
bool Event_Handler::is_window_running() {
    return is_running;
}

void Event_Handler::start_game() {
    is_game_started = true;
}

void Event_Handler::suscribe_to_touchEvent(std::function<void()>& func) {
    touch_events[number_of_touch_events] = func;
    ++number_of_touch_events;
}

void Event_Handler::execute_touch_events() {
    for(int i{0};i<number_of_touch_events;++i){
        touch_events[i]();
    }
}

void Event_Handler::update() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_FINGERDOWN:
            execute_touch_events();
            break;
        default:
            break;
    }
}

Event_Handler::Event_Handler():
is_game_started{false},is_running{true},number_of_touch_events{0},number_of_die_events{0}
{

}

void Event_Handler::suscribe_to_DieEvent(std::function<void()> &func) {
    die_events[number_of_die_events] = func;
    ++number_of_die_events;
}

void Event_Handler::execute_Die() {
    for(int i{0};i<number_of_die_events;++i){
        die_events[i]();
    }
}

Event_Handler& Event_Handler::get_instance() {
    if(instance== nullptr){
        instance = new Event_Handler();
    }
    return *instance;
}