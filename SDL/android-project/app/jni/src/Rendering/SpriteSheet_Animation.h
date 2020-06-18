//
// Created by migue on 16/01/2020.
//

#ifndef ANDROID_PROJECT_SPRITESHEET_ANIMATION_H
#define ANDROID_PROJECT_SPRITESHEET_ANIMATION_H

#include <SDL.h>
#include <string>
#include "../pixel_coord.h"

struct SpriteSheet_AnimationDef{
    unsigned int y_offset;
    unsigned int x_offset;
    unsigned int frame_index;
    unsigned int number_of_frames;
    SDL_RendererFlip flip;
};

class SpriteSheet_Animation{

    unsigned int sprite_size;
    SDL_Texture* my_tex;
    unsigned int scale_x;
    unsigned int scale_y;
    SDL_Rect     rect_cut;
public:
    SpriteSheet_Animation(std::string,SDL_Renderer*,unsigned int,
            unsigned int , unsigned int, SDL_Rect);
    void render( SDL_Renderer&, SpriteSheet_AnimationDef, unsigned int, unsigned int);
    SpriteSheet_Animation& operator=(const SpriteSheet_Animation&) = default;
    pixel_coord get_size();
    SDL_Rect get_rect();
    ~SpriteSheet_Animation();
};


#endif //ANDROID_PROJECT_SPRITESHEET_ANIMATION_H
