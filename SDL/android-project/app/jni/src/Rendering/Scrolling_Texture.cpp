//
// Created by migue on 17/01/2020.
//

#include "Scrolling_Texture.h"

#include <android/log.h>
#include <stdlib.h>


Scrolling_Texture::Scrolling_Texture(std::string image_path, float scale_x, float scale_y,
                                     SDL_Rect rect_cut, SDL_Renderer *renderer):
        scale_x{scale_x},scale_y{scale_y},
        rect_cut{rect_cut},x{0}
        {
        SDL_Surface* image = IMG_Load(image_path.c_str());
        if(image== nullptr){
            __android_log_print(ANDROID_LOG_ERROR, "TRACKERS", "Couldn't Create Image: %s", image_path.c_str());
            return;
        }
        my_texture = SDL_CreateTextureFromSurface(renderer,image);
}

void Scrolling_Texture::scroll_right(float scroll_ammount) {
    x += (unsigned int)(scroll_ammount*MAX_SCROLL_VAL);
}

void Scrolling_Texture::scroll_left(float scroll_ammount) {
    x -= (unsigned int)(scroll_ammount*MAX_SCROLL_VAL);
}

void Scrolling_Texture::render(SDL_Renderer& renderer){
    int x = this->x%MAX_SCROLL_VAL;

    SDL_Rect first_src_rect;
    first_src_rect.x = rect_cut.x ;
    first_src_rect.y = rect_cut.y;
    first_src_rect.w = (((MAX_SCROLL_VAL-x)*rect_cut.w)/MAX_SCROLL_VAL);
    first_src_rect.h = rect_cut.h;

    SDL_Rect first_dst_rect;
    first_dst_rect.x = (int)(((x*rect_cut.w)/MAX_SCROLL_VAL) * scale_x);
    first_dst_rect.y = pos.y;
    first_dst_rect.w = (int)(first_src_rect.w * scale_x);
    first_dst_rect.h = (int)(first_src_rect.h * scale_y);

    SDL_RenderCopy(&renderer,my_texture,&first_src_rect,&first_dst_rect);

    SDL_Rect second_src_rect;
    second_src_rect.x = (int)(((MAX_SCROLL_VAL-x)*rect_cut.w)/MAX_SCROLL_VAL) + rect_cut.x;
    second_src_rect.y = rect_cut.y;
    second_src_rect.w = (int)((x*rect_cut.w)/MAX_SCROLL_VAL);
    second_src_rect.h = rect_cut.h;

    SDL_Rect second_dst_rect;
    second_dst_rect.x = pos.x;
    second_dst_rect.y = pos.y;
    second_dst_rect.w = (int)(second_src_rect.w * scale_x);
    second_dst_rect.h = (int)(second_src_rect.h * scale_y);

    SDL_RenderCopy(&renderer,my_texture,&second_src_rect,&second_dst_rect);
}

Scrolling_Texture::~Scrolling_Texture() {
    SDL_DestroyTexture(my_texture);
}