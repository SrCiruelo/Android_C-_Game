//
// Created by migue on 16/01/2020.
//

#include <SDL_image.h>
#include <pixel_coord.h>
#include "SpriteSheet_Animation.h"

SpriteSheet_Animation::SpriteSheet_Animation(std::string image_path
                , SDL_Renderer * renderer,unsigned int sprite_size
                , unsigned int scale_x, unsigned int scale_y,
                SDL_Rect rect_cut):
scale_x{scale_x},scale_y{scale_y},rect_cut{rect_cut},sprite_size{sprite_size}
{
    SDL_Surface* image = IMG_Load(image_path.c_str());
    if(image== nullptr){
        SDL_Log("Error creating Window");
        SDL_Log("SDL Error: %s", SDL_GetError());
        return;
    }
    my_tex = SDL_CreateTextureFromSurface(renderer,image);
}


pixel_coord SpriteSheet_Animation::get_size() {
    pixel_coord tmp(rect_cut.w * scale_x,rect_cut.h * scale_y);
    return tmp;
}
void SpriteSheet_Animation::render(SDL_Renderer& renderer, SpriteSheet_AnimationDef spriteDef,
                                   unsigned int x, unsigned int y) {
    SDL_Rect src_Rect ;
    src_Rect.x = spriteDef.frame_index *sprite_size + rect_cut.x + spriteDef.x_offset;
    src_Rect.y = spriteDef.y_offset+ rect_cut.y;
    src_Rect.w = rect_cut.w;
    src_Rect.h = rect_cut.h;

    SDL_Rect dst_Rect;
    dst_Rect.x = x;
    dst_Rect.y = y;
    dst_Rect.w = rect_cut.w * scale_x;
    dst_Rect.h = rect_cut.h * scale_y;

    SDL_RenderCopyEx(&renderer,my_tex,&src_Rect,&dst_Rect,0,NULL,spriteDef.flip);
}

SDL_Rect SpriteSheet_Animation::get_rect() {
    return rect_cut;
}

SpriteSheet_Animation::~SpriteSheet_Animation() {
    SDL_DestroyTexture(my_tex);
}