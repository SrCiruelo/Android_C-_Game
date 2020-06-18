//
// Created by migue on 19/01/2020.
//

#ifndef ANDROID_PROJECT_EVENT_HANDLER_H
#define ANDROID_PROJECT_EVENT_HANDLER_H

#define MAX_SUSCRIBERS 10

#include <functional>


class Event_Handler {
private:

    unsigned int number_of_touch_events;
    unsigned int number_of_die_events;
    bool is_game_started;
    bool is_running;
    static Event_Handler* instance;

    void execute_touch_events();
    Event_Handler();
    std::function<void()> touch_events [MAX_SUSCRIBERS];
    std::function<void()> die_events   [MAX_SUSCRIBERS];
public:
    bool has_started();
    void start_game();
    void suscribe_to_touchEvent(std::function<void()>& func);
    bool is_window_running();
    void update();
    void suscribe_to_DieEvent(std::function<void()>& func);
    void execute_Die();

    static Event_Handler& get_instance();

};


#endif //ANDROID_PROJECT_EVENT_HANDLER_H
