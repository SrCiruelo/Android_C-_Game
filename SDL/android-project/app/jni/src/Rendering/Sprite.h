//
// Created by migue on 16/01/2020.
//

#ifndef ANDROID_PROJECT_SPRITE_H
#define ANDROID_PROJECT_SPRITE_H

#include "SpriteSheet_Animation.h"
#include "Rendereable.h"
#include <memory>

#define MAX_ANIMATIONS 10

class Sprite:public Rendereable{
private:
    SpriteSheet_Animation*    my_animation;
    SpriteSheet_AnimationDef  animation_definitions[MAX_ANIMATIONS];
    unsigned int current_animation_index;
    unsigned int number_of_animations;

    //tmp
    std::allocator<SpriteSheet_Animation> al;
public:
    Sprite();
    void render(SDL_Renderer&) override;
    void CreateSpriteSheet(std::string,SDL_Renderer*, unsigned int, unsigned int, unsigned int,SDL_Rect);
    void set_animation(unsigned int);
    void create_animation(unsigned int ,unsigned int ,unsigned int ,unsigned int,SDL_RendererFlip  );
    void step_current_animation();
    void step_back_current_animation();
    pixel_coord get_size();
    SDL_Rect    get_rect();

    const SpriteSheet_AnimationDef& get_animation_info();
    unsigned int get_current_animation_index();
    ~Sprite();
};


#endif //ANDROID_PROJECT_SPRITE_H
