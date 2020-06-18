//
// Created by migue on 03/02/2020.
//

#include "Obstacle_Handler.h"
#include <utility>

#include <stdlib.h>

Obstacle_Stats::Obstacle_Stats():
probabilidad_de_generacion{0}{}

Obstacle_Stats::Obstacle_Stats(float probabilidad_de_generacion):
probabilidad_de_generacion{probabilidad_de_generacion}{};

Obstacle_Handler::Obstacle_Handler(Game_Renderer* renderer,
                                   std::function<float(float)> spawn_ratio,
                                   std::function<float(float)> speed_ratio):
renderer{renderer},spawn_ratio{std::move(spawn_ratio)},
speed_ratio{std::move(speed_ratio)},number_of_obstacles{0},
y_generation_coord{0},current_enemy_index{0}
{}

void Obstacle_Handler::Attach_Obstacle(Obstacle_Controller *controller, Obstacle_Stats stats)
{
    my_obstacles[number_of_obstacles] = controller;
    my_obstacles_stats[number_of_obstacles] = stats;
    if(number_of_obstacles!=current_enemy_index)
        set_Controller_resting(controller);
    else
        set_Controller_active(controller);
    ++number_of_obstacles;
}


void Obstacle_Handler::update() {
    float current_time = SDL_GetTicks()/1000.0f;
    float time_passed  = current_time - last_time;
    last_time          = current_time;
    my_time            += time_passed;

    //AQUÍ
    //Tiene que depender de la función dada
    if(my_time>2){
        my_time = 0;
        unsigned int random_index = get_random_Controller_Index();
        //si random_index es el mismo no debería hacer esto
        if(random_index!=current_enemy_index){
            set_Controller_active(my_obstacles[random_index]);
            current_enemy_index = random_index;
        }
    }

    for(int i{0};i<number_of_obstacles;++i){
        my_obstacles[i]->update();
    }

    if(current_enemy_index!= MAX_OBSTACLES &&
    my_obstacles[current_enemy_index]->get_pos().x+ my_obstacles[current_enemy_index]->get_sprite().get_size().x< 0){
        set_Controller_resting(my_obstacles[current_enemy_index]);
        current_enemy_index = MAX_OBSTACLES;
    }
}

void Obstacle_Handler::set_Controller_resting(Obstacle_Controller* controller) {
    controller->set_vel(pixel_coord(0,0));
    controller->set_pos(pixel_coord(-200,-200));
    renderer->set_disable(controller->get_sprite());
}

void Obstacle_Handler::set_Controller_active(Obstacle_Controller* controller) {
    //AQUÍ
    //Tiene que depender de la función de velocidad dada
    float speed = -500;
    controller->set_vel(pixel_coord(speed,0));
    renderer->set_able(controller->get_sprite());
    pixel_coord generation_pos = renderer->get_SCREEN_SIZE();
    generation_pos.y           = y_generation_coord;
    generation_pos.x           += + controller->get_sprite().get_size().x;
    controller->set_pos(generation_pos);
}

unsigned int Obstacle_Handler::get_random_Controller_Index() {
    //No debería devolver uno en uso
    unsigned int random_percent = (unsigned int)rand() % 100;
    float current_percentage = 0;
    unsigned int i{0};
    for(;i<number_of_obstacles-1 &&
         (random_percent<=current_percentage ||
          random_percent>=current_percentage+my_obstacles_stats[i].probabilidad_de_generacion)
            ;++i){
        current_percentage += my_obstacles_stats[i].probabilidad_de_generacion;
    }
    return i;
}

void Obstacle_Handler::set_y_Generation_coord(unsigned int y_coord) {
    y_generation_coord = y_coord;
}