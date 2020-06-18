//
// Created by migue on 03/02/2020.
//

#ifndef ANDROID_PROJECT_OBSTACLE_HANDLER_H
#define ANDROID_PROJECT_OBSTACLE_HANDLER_H

#include <Functional>
#include "Obstacle_Controller.h"

#define MAX_OBSTACLES 10
struct Obstacle_Stats{
    float probabilidad_de_generacion;
    Obstacle_Stats();
    Obstacle_Stats(float probabilidad_de_generacion);
    Obstacle_Stats(Obstacle_Stats&) = default;
    Obstacle_Stats(Obstacle_Stats&&) = default;
    Obstacle_Stats& operator=(Obstacle_Stats&)= default;
    Obstacle_Stats& operator=(Obstacle_Stats&&)= default;
};

//Hay que modificarlo para que pueda haber más de un enemigo en pantalla
class Obstacle_Handler {
    std::function<float(float)> speed_ratio;
    std::function<float(float)> spawn_ratio;
    Obstacle_Controller* my_obstacles[MAX_OBSTACLES];
    Obstacle_Stats      my_obstacles_stats[MAX_OBSTACLES];
    unsigned int        number_of_obstacles;
    Game_Renderer*       renderer;

    float               my_time;
    float               last_time;

    unsigned int        current_enemy_index;
    unsigned int        y_generation_coord;
    void                set_Controller_resting(Obstacle_Controller* controller);
    void                set_Controller_active (Obstacle_Controller* controller);
    unsigned int        get_random_Controller_Index();
public:
    Obstacle_Handler(Game_Renderer* renderer,std::function<float(float)> spawn_ratio,
                     std::function<float(float)> speed_ratio);
    void Attach_Obstacle(Obstacle_Controller* controller,Obstacle_Stats stats);
    void set_y_Generation_coord(unsigned int y_coord);
    void update();
};


#endif //ANDROID_PROJECT_OBSTACLE_HANDLER_H
