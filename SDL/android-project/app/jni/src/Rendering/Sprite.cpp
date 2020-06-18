//
// Created by migue on 16/01/2020.
//

#include "Sprite.h"


Sprite::Sprite():
number_of_animations{0},current_animation_index{0},Rendereable({0,0})
{
    my_animation = al.allocate(1);
}

void Sprite::render(SDL_Renderer & renderer) {
    my_animation->render(renderer,animation_definitions[current_animation_index],pos.x,pos.y);
}

pixel_coord Sprite::get_size() {
    return my_animation->get_size();
}

void Sprite::CreateSpriteSheet(std::string image_path
        , SDL_Renderer * renderer, unsigned int sprite_size
        ,unsigned int scale_x,unsigned int scale_y
        ,SDL_Rect rect_cut) {

    al.construct(my_animation,
            image_path,renderer,sprite_size,
            scale_x,scale_y,rect_cut);
}

void Sprite::set_animation(unsigned int anim_index) {
    if(anim_index>=number_of_animations){
        return;
    }
    animation_definitions[current_animation_index].frame_index = 0;
    current_animation_index = anim_index;
}
void Sprite::create_animation(unsigned int x_offset,unsigned int y_offset,
                           unsigned int frame_index, unsigned int number_of_frames,SDL_RendererFlip flip){
    animation_definitions[number_of_animations] = {y_offset,x_offset,frame_index,number_of_frames,flip};
    ++number_of_animations;
}

void Sprite::step_current_animation() {
    SpriteSheet_AnimationDef& my_def = animation_definitions[current_animation_index];
    ++my_def.frame_index;
    if(my_def.frame_index>=my_def.number_of_frames){
        my_def.frame_index = 0;
    }

}

void Sprite::step_back_current_animation() {
    SpriteSheet_AnimationDef& my_def = animation_definitions[current_animation_index];
    if(my_def.frame_index==0){
        my_def.frame_index = my_def.number_of_frames-1;
    }
    --my_def.frame_index;
}

Sprite::~Sprite() {
    al.destroy(my_animation);
    al.deallocate(my_animation,1);
}

const SpriteSheet_AnimationDef& Sprite::get_animation_info() {
    return  animation_definitions[current_animation_index];
}

unsigned int Sprite::get_current_animation_index() {
    return current_animation_index;
}

SDL_Rect Sprite::get_rect() {
    return my_animation->get_rect();
}
