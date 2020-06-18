//
// Created by migue on 19/01/2020.
//

#ifndef ANDROID_PROJECT_CHARACTER_CONTROLLER_H
#define ANDROID_PROJECT_CHARACTER_CONTROLLER_H


#include "../Rendering/Sprite.h"
#include "../Physics/Dynamic_Physic_Object.h"
#include "../Rendering/Game_Renderer.h"
#include "../Physics/Collision_Handler.h"

class Character_Controller {
    Sprite*                  my_sprite;
    Dynamic_Physic_Object*  physic_object;

    bool                    is_alive;
    bool                    can_move();
    bool                    on_ground();
    void            detect_collisions(b2Contact *contact);
public:
    Character_Controller(My_B2_World& physics_world,Game_Renderer &game_renderer,
                         b2Filter character_filter);
    void jump();
    void update();
    void update_animation();
    Sprite& get_sprite();
    void die();

    ~Character_Controller();
};


#endif //ANDROID_PROJECT_CHARACTER_CONTROLLER_H
