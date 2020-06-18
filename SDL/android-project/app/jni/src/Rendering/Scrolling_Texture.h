//
// Created by migue on 17/01/2020.
//

#ifndef ANDROID_PROJECT_SCROLLING_TEXTURE_H
#define ANDROID_PROJECT_SCROLLING_TEXTURE_H

#include "Rendereable.h"
#include <SDL.h>
#include <string>
#include <SDL_IMAGE.h>

#define MAX_SCROLL_VAL 10000

class Scrolling_Texture: public Rendereable {
    ///Scroll offset
    unsigned int x;
    float scale_x;
    float scale_y;
    SDL_Rect     rect_cut;
    SDL_Texture* my_texture;
public:
    Scrolling_Texture(std::string image_path,
                    float scale_x, float scale_y,
                    SDL_Rect rect_cut, SDL_Renderer* renderer);
    Scrolling_Texture(Scrolling_Texture&)= default;
    Scrolling_Texture(Scrolling_Texture&&)= default;
    void render(SDL_Renderer&) override ;
    void scroll_right(float scroll_ammount);
    void scroll_left (float scroll_ammount);
    ~Scrolling_Texture();
};


#endif //ANDROID_PROJECT_SCROLLING_TEXTURE_H
