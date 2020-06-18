//
// Created by migue on 19/01/2020.
//

#include "Character_Controller.h"
#include <string>
#include "Event_Handler.h"
#include "../../box2d/include/box2d/box2d.h"

#include <android/log.h>

typedef  void (Character_Controller::*Void_Member_Function)();

Character_Controller::Character_Controller(My_B2_World& physics_world,Game_Renderer &game_renderer,
        b2Filter character_filter):is_alive{true}
    {
        pixel_coord screen_size = game_renderer.get_SCREEN_SIZE();
        SDL_Rect sprite_rect = {4,3,15,18};
        unsigned int sprite_scale_x = 8;
        unsigned int sprite_scale_y = 8;
        my_sprite = new Sprite();
        my_sprite->CreateSpriteSheet("DinoSprites - doux.png",&game_renderer.get_renderer(),24,sprite_scale_x,sprite_scale_y,sprite_rect);
        my_sprite->create_animation(0,0,0,3,SDL_FLIP_NONE);
        my_sprite->create_animation(24*4,0,0,6,SDL_FLIP_NONE);
        my_sprite->create_animation(24*14,0,0,3,SDL_FLIP_NONE);
        my_sprite->set_animation(1);
        pixel_coord sprite_coords;
        sprite_coords.x = 200;
        sprite_coords.y = 0;
        my_sprite->set_pos(sprite_coords);

        pixel_coord screen_sprite_size;

        screen_sprite_size.x = sprite_rect.w * sprite_scale_x + screen_size.x/2;
        screen_sprite_size.y = screen_size.y/2 - sprite_rect.h*sprite_scale_y;
        b2Vec2 real_sprite_size = physics_world.pixel_to_b2Vec(screen_sprite_size);

        pixel_coord screen_sprite_pos;
        screen_sprite_pos.x = sprite_coords.x + sprite_rect.w/2;
        screen_sprite_pos.y = sprite_coords.y + sprite_rect.h/2;
        b2Vec2 real_sprite_pos = physics_world.pixel_to_b2Vec(screen_sprite_pos);

        physic_object = new Dynamic_Physic_Object(physics_world,real_sprite_size,real_sprite_pos,1,0.3,true, character_filter,CHARACTER_ENTITY_TYPE);
        physic_object->AttachSprite(*my_sprite);

        std::function<void()> my_func = [&](){ this->jump();};
        Event_Handler::get_instance().suscribe_to_touchEvent(my_func);
        std::function<void(b2Contact *)> die_func = [&](b2Contact *contact){ this->detect_collisions(contact);};
        physics_world.suscribe_to_collsion_Event(die_func);
}


void Character_Controller::die() {
    is_alive = false;
    physic_object->set_physical_vel({0,0});
    Event_Handler::get_instance().execute_Die();
}


void Character_Controller::detect_collisions(b2Contact *contact) {
    void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();
    if(bodyUserDataA && bodyUserDataB){
        unsigned int entity_type0 = static_cast<PhysicsObject*>( bodyUserDataA )->get_entity_type();
        unsigned int entity_type1 = static_cast<PhysicsObject*>( bodyUserDataB )->get_entity_type();
        if(((entity_type0==OBSTACLE_ENTITY_TYPE)!=(entity_type1==OBSTACLE_ENTITY_TYPE)) && ((entity_type0==CHARACTER_ENTITY_TYPE)!=(entity_type1==CHARACTER_ENTITY_TYPE))){
            die();
        }
        return;
    }
    __android_log_print(ANDROID_LOG_ERROR, "TRACKERS", "%s", "Collision was detected but it wasn't an enemy");
}

void Character_Controller::jump() {
    if(is_alive && on_ground())
    physic_object->Apply_Impulse(b2Vec2(0,75.0f));
}

void Character_Controller::update() {
    if(physic_object->get_physical_vel().y<0){
        physic_object->set_gravityScale(8.5f);
    }
    else{
        physic_object->set_gravityScale(7);
    }
    physic_object->update();

}

void Character_Controller::update_animation() {
    unsigned int animation_index = my_sprite->get_current_animation_index();
    if(!is_alive ){
        if(animation_index!=2) my_sprite->set_animation(2);
    }
    else if(can_move()){
        if(animation_index!=1)my_sprite->set_animation(1);
    }
    else if(animation_index!=0){
        my_sprite->set_animation(0);
    }

    SpriteSheet_AnimationDef animationDef = my_sprite->get_animation_info();
    if(animation_index!=2 || animationDef.frame_index<animationDef.number_of_frames-1 ){
        my_sprite->step_current_animation();
    }
}

bool Character_Controller::can_move() {
    return Event_Handler::get_instance().has_started();
}

bool Character_Controller::on_ground() {
    //Get ContactList
    b2ContactEdge* lst = physic_object->Get_Contact_list();
    return lst!= nullptr;
}

Character_Controller::~Character_Controller() {
    delete my_sprite;
    delete physic_object;
}

Sprite& Character_Controller::get_sprite() {
    return *my_sprite;
}