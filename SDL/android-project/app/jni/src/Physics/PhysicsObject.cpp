//
// Created by migue on 18/01/2020.
//

#include "PhysicsObject.h"

unsigned int PhysicsObject::get_entity_type() {
    return entity_type;
}
PhysicsObject::PhysicsObject(My_B2_World &world,unsigned int entity_type):world{world},my_sprite{nullptr},entity_type{entity_type}{

}

void PhysicsObject::AttachSprite(Sprite& sprite) {
    my_sprite = &sprite;
}

b2ContactEdge* PhysicsObject::Get_Contact_list(){
    return my_body->GetContactList();
}

void PhysicsObject::update() {
    if(my_sprite!= nullptr){
        pixel_coord tmp = world.b2Vec_to_pixel( my_body->GetPosition());
        pixel_coord sprite_size = my_sprite->get_size();
        tmp.x -= sprite_size.x/2;
        tmp.y -= sprite_size.y/2;
        my_sprite->set_pos(tmp);
    }


}

b2Vec2 PhysicsObject::get_physical_pos() {
    return my_body->GetPosition();
}


void PhysicsObject::set_physical_pos(b2Vec2 pos) {
    my_body->SetTransform(b2Vec2(pos),0);
}

void PhysicsObject::Apply_Force(b2Vec2 force) {
    my_body->ApplyForceToCenter(force,true);
}

void PhysicsObject::Apply_Impulse(b2Vec2 force) {
    my_body->ApplyLinearImpulseToCenter(force,true);
}

void PhysicsObject::set_gravityScale(float scale) {
    my_body->SetGravityScale(scale);
}

void PhysicsObject::set_pixel_pos(pixel_coord pos) {
    my_body->SetTransform(world.pixel_to_b2Vec(pos),0);
}

void PhysicsObject::set_pixel_vel(pixel_coord vel) {
    my_body->SetLinearVelocity(world.pixelScale_to_vecScale(vel));
}

b2Vec2 PhysicsObject::get_physical_vel() {
    return  my_body->GetLinearVelocity();
}

void PhysicsObject::set_physical_vel(b2Vec2 vel) {
    my_body->SetLinearVelocity(vel);
}

pixel_coord PhysicsObject::get_pixel_pos() {
    return world.b2Vec_to_pixel(my_body->GetPosition());
}

pixel_coord PhysicsObject::get_pixel_vel() {
    return world.vecScale_to_pixelScale(my_body->GetLinearVelocity());
}