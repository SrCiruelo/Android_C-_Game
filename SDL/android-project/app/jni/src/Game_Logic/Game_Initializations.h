//
// Created by migue on 17/01/2020.
//

#ifndef ANDROID_PROJECT_GAME_INITIALIZATIONS_H
#define ANDROID_PROJECT_GAME_INITIALIZATIONS_H

#include "../Rendering/Game_Renderer.h"
#include "../Rendering/Sprite.h"
#include "../Rendering/Scrolling_Texture.h"
#include "../Physics/My_B2_World.h"
#include "../Physics/Static_Physic_Object.h"

#include <memory>
#include "Character_Controller.h"
#include "Obstacle_Controller.h"
#include "Animation_Handler.h"
#include "Obstacle_Handler.h"

#define MAX_SCROLLING_TEX 20
#define MAX_OBSTACLES 20

class Game_Initializations {

public:

    Scrolling_Texture* scrolling_textures;
    unsigned int       number_of_scrollingTex;
    Sprite*            obstacles_sprites;
    unsigned int       number_of_obstacles;
    My_B2_World&       physics_world;

    Static_Physic_Object*  ground_object;
    Obstacle_Controller*   obstacle_0;
    Character_Controller*  player;


    std::allocator<Scrolling_Texture> scrolling_tex_al;
    std::allocator<Sprite>            character_sprite_al;
    std::allocator<Sprite>            obstacles_sprite_al;


    Game_Initializations(Animation_Handler& animation_handler,Game_Renderer& game_renderer,
            Obstacle_Handler& obstacle_handler,My_B2_World& physics_world);
    ~Game_Initializations();
};


#endif //ANDROID_PROJECT_GAME_INITIALIZATIONS_H
