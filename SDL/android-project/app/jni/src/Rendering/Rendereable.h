//
// Created by migue on 16/01/2020.
//

#ifndef ANDROID_PROJECT_RENDEREABLE_H
#define ANDROID_PROJECT_RENDEREABLE_H

#include <SDL.h>
#include "../pixel_coord.h"

class Rendereable{
protected:
    pixel_coord pos;
    Rendereable(pixel_coord pos):pos{pos}{};
    Rendereable(Rendereable&)= default;
    Rendereable(Rendereable&&)= default;
    Rendereable():pos(){};
public:
    virtual void render( SDL_Renderer&)=0;
    virtual void set_pos(pixel_coord new_pos){
        pos = new_pos;
    }
    virtual inline pixel_coord get_pos(){return pos;}
};
#endif //ANDROID_PROJECT_RENDEREABLE_H
