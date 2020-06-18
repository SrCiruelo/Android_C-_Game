//
// Created by migue on 18/01/2020.
//

#include "My_B2_World.h"

My_B2_World::My_B2_World(b2Vec2 gravity, unsigned int SCREEN_WIDTH,unsigned int SCREEN_HEIGHT)
:world(gravity),SCREEN_WIDTH{SCREEN_WIDTH},SCREEN_HEIGHT{SCREEN_HEIGHT} {
    world.SetContactListener(&collision_handler);
}

b2Body* My_B2_World::Create_Body_Static_Box(b2Vec2 box_dimensions, b2Vec2 center_position,b2Filter collision_mask) {

    b2BodyDef body_def;
    body_def.position.Set(center_position.x,center_position.y);
    b2Body* body = world.CreateBody(&body_def);

    b2PolygonShape box;
    box.SetAsBox(box_dimensions.x/2,box_dimensions.y/2);

    b2FixtureDef fixture_def;
    fixture_def.shape = &box;
    fixture_def.density = 0;
    fixture_def.friction = 0;
    fixture_def.filter = collision_mask;

    body->CreateFixture(&fixture_def);

    return body;
}

b2Body* My_B2_World::Create_Body_Dynamic_Box(b2Vec2 box_dimensions, b2Vec2 center_position,
                                             float density, float friction, bool FixedRotation,b2Filter collision_mask) {

    b2BodyDef body_def;
    body_def.type = b2_dynamicBody;
    body_def.fixedRotation = FixedRotation;
    body_def.position.Set(center_position.x,center_position.y);
    b2Body* body = world.CreateBody(&body_def);

    b2PolygonShape box;
    box.SetAsBox(box_dimensions.x/2,box_dimensions.y/2);

    b2FixtureDef fixture_def;
    fixture_def.shape = &box;
    fixture_def.density = density;
    fixture_def.friction = friction;
    fixture_def.filter = collision_mask;

    body->CreateFixture(&fixture_def);

    return body;
}

b2Body* My_B2_World::Create_Body_Dynamic_Trigger(b2Vec2 box_dimensions, b2Vec2 center_position, b2Filter collision_mask) {
    b2BodyDef body_def;
    body_def.type = b2_dynamicBody;
    body_def.fixedRotation = true;
    body_def.position.Set(center_position.x,center_position.y);
    body_def.gravityScale = 0;
    b2Body* body = world.CreateBody(&body_def);

    b2PolygonShape box;
    box.SetAsBox(box_dimensions.x/2,box_dimensions.y/2);

    b2FixtureDef fixture_def;
    fixture_def.shape    = &box;
    fixture_def.density  = 1;
    fixture_def.friction = 0;
    fixture_def.isSensor = true;
    fixture_def.filter = collision_mask;

    body->CreateFixture(&fixture_def);

    return body;
}

b2Vec2      My_B2_World::pixel_to_b2Vec(pixel_coord coord){
    b2Vec2 tmp;
    float tx = (float)coord.x/(float)SCREEN_WIDTH;
    tmp.x    = (1-tx)*left_b2_screen_coord + tx*right_b2_screen_coord;
    float ty = (float)coord.y/(float)SCREEN_HEIGHT;
    tmp.y    = (1-ty)*top_b2_screen_coord  + ty*bottom_b2_screen_coord;
    return  tmp;
}

pixel_coord My_B2_World::b2Vec_to_pixel(b2Vec2      coord){
    pixel_coord tmp;

    float abs_x = right_b2_screen_coord - left_b2_screen_coord;
    float tx    = (coord.x-left_b2_screen_coord)/abs_x;
    tmp.x       = (int)(tx*SCREEN_WIDTH);

    float abs_y = bottom_b2_screen_coord - top_b2_screen_coord;
    float ty    = (coord.y- top_b2_screen_coord)/abs_y ;
    tmp.y       = (int)(ty*SCREEN_HEIGHT);
    return tmp;
}

pixel_coord My_B2_World::vecScale_to_pixelScale(b2Vec2 size) {
    pixel_coord tmp;
    tmp.x = (unsigned int)(size.x/canvas_x_SIZE * SCREEN_WIDTH);
    tmp.y = (unsigned int)(size.y/canvas_y_SIZE * SCREEN_HEIGHT);
    return tmp;
}

b2Vec2 My_B2_World::pixelScale_to_vecScale(pixel_coord size) {
    b2Vec2 tmp;
    tmp.x = (float)size.x/SCREEN_WIDTH * canvas_x_SIZE;
    tmp.y = (float)size.y/SCREEN_HEIGHT * canvas_y_SIZE;
    return tmp;
}

void My_B2_World::physics_step(float timeStep, int32 velocityIterations,
                               int32 positionIterations) {
    world.Step(timeStep,velocityIterations,positionIterations);
}

void My_B2_World::suscribe_to_collsion_Event(std::function<void(b2Contact *)> my_func) {
    collision_handler.suscribe_to_collision_Event(my_func);
}