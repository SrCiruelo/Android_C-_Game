//
// Created by migue on 17/01/2020.
//

#include "Game_Renderer.h"
#include <algorithm>

Game_Renderer::Game_Renderer(SDL_Renderer *renderer):renderer{renderer},number_of_redereables{0} {
}

void Game_Renderer::render() {

    SDL_RenderClear(renderer);
    for(unsigned int i{0};i<number_of_redereables;++i){
        if(render_objects[i].is_able)render_objects[i].rendereable->render(*renderer);
    }
    SDL_RenderPresent(renderer);
}

const unsigned int& Game_Renderer::attach_rendereable(Rendereable &rendereable) {
    render_objects[number_of_redereables].rendereable = &rendereable;
    render_objects[number_of_redereables].is_able     = true;
    render_objects[number_of_redereables].queue_index = number_of_redereables;
    ++number_of_redereables;
    return render_objects[number_of_redereables].queue_index;
}

void Game_Renderer::set_disable(Rendereable &rendereable) {
    int i{0};
    for(;i<number_of_redereables && &rendereable != render_objects[i].rendereable;++i);
    if(i==number_of_redereables)return;//Exception Here
    else render_objects[i].is_able = false;
}
void Game_Renderer::set_able(Rendereable &rendereable) {
    int i{0};
    for(;i<number_of_redereables && &rendereable != render_objects[i].rendereable;++i);
    if(i==number_of_redereables)return;//Exception Here
    else render_objects[i].is_able = true;
}

const unsigned int& Game_Renderer::get_render_queue_index(Rendereable &rendereable) {
    int i{0};
    for(;i<number_of_redereables && &rendereable != render_objects[i].rendereable;++i);
    if(i!=number_of_redereables){
        return render_objects[i].queue_index;
    }
    else{
        //Exception Here
    }
}

void Game_Renderer::set_disable(unsigned int render_queue_index) {
    if(render_queue_index<number_of_redereables){
        render_objects[render_queue_index].is_able = false;
    }
    else{
        //Exception Here
    }
}
void Game_Renderer::set_able(unsigned int render_queue_index) {
    if(render_queue_index<number_of_redereables){
        render_objects[render_queue_index].is_able = true;
    }
    else{
        //Exception Here
    }
}

void Game_Renderer::deattach_rendereable(Rendereable &rendereable) {
    unsigned int index = get_render_queue_index(rendereable);
    unsigned int i{index};
    --number_of_redereables;
    for(;i<number_of_redereables;++i){
        render_objects[i] = render_objects[i+1];
    }
}
void Game_Renderer::deattach_rendereable(unsigned int render_queue_index) {
    if(render_queue_index<number_of_redereables){
        render_objects[render_queue_index].is_able = true;
        unsigned int i{render_queue_index};
        --number_of_redereables;
        for(;i<number_of_redereables;++i){
            render_objects[i] = render_objects[i+1];
        }
    }
    else{
        //Exception Here
    }

}

pixel_coord Game_Renderer::get_SCREEN_SIZE() {
    pixel_coord tmp;
    SDL_GetRendererOutputSize(renderer,&tmp.x,&tmp.y);
    return tmp;
}

SDL_Renderer& Game_Renderer::get_renderer() {return *renderer;}