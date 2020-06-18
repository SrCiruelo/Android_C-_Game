//
// Created by migue on 17/01/2020.
//

#include "Game_Initializations.h"


Game_Initializations::~Game_Initializations() {
    for(int i{0};i<number_of_scrollingTex;++i){
        scrolling_tex_al.destroy(scrolling_textures+i);
    }
    for(int i{0};i<number_of_obstacles;++i){
        obstacles_sprite_al.destroy(obstacles_sprites+i);
    }
    scrolling_tex_al.deallocate(scrolling_textures,MAX_SCROLLING_TEX);
    obstacles_sprite_al.deallocate(obstacles_sprites,MAX_OBSTACLES);

    delete player;
    delete obstacle_0;
}

Game_Initializations::Game_Initializations(Animation_Handler& animation_handler,Game_Renderer &game_renderer,
        Obstacle_Handler& obstacle_handler,My_B2_World& physics_world)
        :physics_world{physics_world},number_of_scrollingTex{0},number_of_obstacles{0} {
    scrolling_textures = scrolling_tex_al.allocate(MAX_SCROLLING_TEX);
    obstacles_sprites  = obstacles_sprite_al.allocate(MAX_OBSTACLES);
    pixel_coord screen_size = game_renderer.get_SCREEN_SIZE();



    ////////////////////////////////////////CHARACTER SPRITE CREATION////////////////////////////////////////



    ////////////////////////////////////////ENEMIES SPRITES CREATION////////////////////////////////////////
    SDL_Rect enemy0_rect = {0,0,57,88};
    unsigned int enemy0_scale_x = 4;
    unsigned int enemy0_scale_y = 4;
    obstacles_sprite_al.construct(obstacles_sprites+number_of_obstacles);
    (obstacles_sprites+number_of_obstacles)->CreateSpriteSheet("andromalius-57x88.png",&game_renderer.get_renderer(),57,enemy0_scale_x,enemy0_scale_y,enemy0_rect );
    (obstacles_sprites+number_of_obstacles)->create_animation(0,0,0,8,SDL_FLIP_HORIZONTAL);
    (obstacles_sprites+number_of_obstacles)->create_animation(0,88,0,8,SDL_FLIP_HORIZONTAL);
    (obstacles_sprites+number_of_obstacles)->set_animation(0);
    pixel_coord enemy0_coords;
    enemy0_coords.x = screen_size.x - screen_size.x/4;
    enemy0_coords.y = screen_size.y*7/8;
    (obstacles_sprites+number_of_obstacles)->set_pos(enemy0_coords);
    ++number_of_obstacles;

    obstacle_handler.set_y_Generation_coord(screen_size.y*7/8);

    //////////////////////////////////////SCROLLING TEXTURES CREATION//////////////////////////////////////
    SDL_Rect suelo_texture_rect;
    unsigned int ground_scale_x = 4;
    unsigned int ground_scale_y = 4;
    suelo_texture_rect.x = 0;
    suelo_texture_rect.y = 793-70;
    suelo_texture_rect.w = 928;
    suelo_texture_rect.h = 70;
    //A veces realizando esta operación crashea
    scrolling_tex_al.construct(scrolling_textures+ number_of_scrollingTex,"Layer_0001_8.png",ground_scale_x ,ground_scale_y,suelo_texture_rect,&game_renderer.get_renderer());
    pixel_coord ground_coords;
    ground_coords.x =  0;
    ground_coords.y =  screen_size.y - 170;
    (scrolling_textures+number_of_scrollingTex)->set_pos(ground_coords);
    ++number_of_scrollingTex; //1

    SDL_Rect scroll_texture_back_rect;
    scroll_texture_back_rect.x = 0;
    scroll_texture_back_rect.y = 793-414;
    scroll_texture_back_rect.w = 928;
    scroll_texture_back_rect.h = 414;
    scrolling_tex_al.construct(scrolling_textures+number_of_scrollingTex,"Layer_0009_2.png",3,3,scroll_texture_back_rect,&game_renderer.get_renderer());
    pixel_coord coords2;
    coords2.x =  0;
    coords2.y =  0;
    (scrolling_textures+number_of_scrollingTex)->set_pos(coords2);
    ++number_of_scrollingTex; //2

    SDL_Rect scroll_texture_arboleda_rect;
    scroll_texture_arboleda_rect.x = 0;
    scroll_texture_arboleda_rect.y = 194;
    scroll_texture_arboleda_rect.w = 928;
    scroll_texture_arboleda_rect.h = 280;
    scrolling_tex_al.construct(scrolling_textures+number_of_scrollingTex,"Layer_0002_7.png",2.5f ,1.8f,scroll_texture_arboleda_rect,&game_renderer.get_renderer());
    pixel_coord coords3;
    coords3.x =  0;
    coords3.y =  0;
    (scrolling_textures+number_of_scrollingTex)->set_pos(coords3);
    ++number_of_scrollingTex; //3

    SDL_Rect scroll_texture_arboles0_rect;
    scroll_texture_arboles0_rect.x = 0;
    scroll_texture_arboles0_rect.y = 458;
    scroll_texture_arboles0_rect.w = 928;
    scroll_texture_arboles0_rect.h = 268;
    scrolling_tex_al.construct(scrolling_textures+number_of_scrollingTex,"Layer_0005_5.png",4 ,4,scroll_texture_arboles0_rect,&game_renderer.get_renderer());
    pixel_coord coords4;
    coords4.x =  0;
    coords4.y =  0;
    (scrolling_textures+number_of_scrollingTex)->set_pos(coords4);
    ++number_of_scrollingTex; //4

    SDL_Rect scroll_texture_arboles1_rect;
    scroll_texture_arboles1_rect.x = 0;
    scroll_texture_arboles1_rect.y = 458;
    scroll_texture_arboles1_rect.w = 928;
    scroll_texture_arboles1_rect.h = 268;
    scrolling_tex_al.construct(scrolling_textures+number_of_scrollingTex,"Layer_0006_4.png",4 ,4,scroll_texture_arboles1_rect,&game_renderer.get_renderer());
    pixel_coord coords5;
    coords5.x =  0;
    coords5.y =  0;
    (scrolling_textures+number_of_scrollingTex)->set_pos(coords5);
    ++number_of_scrollingTex; //5

    SDL_Rect scroll_texture_front_rect;
    scroll_texture_front_rect.x = 0;
    scroll_texture_front_rect.y = 793-80;
    scroll_texture_front_rect.w = 928;
    scroll_texture_front_rect.h = 80;
    scrolling_tex_al.construct(scrolling_textures+number_of_scrollingTex,"Layer_0000_9.png",4 ,4,scroll_texture_front_rect,&game_renderer.get_renderer());
    pixel_coord coords6;
    coords6.x =  0;
    coords6.y =  screen_size.y - 140;
    (scrolling_textures+number_of_scrollingTex)->set_pos(coords6);
    ++number_of_scrollingTex; //6

    SDL_Rect scroll_texture_luz0_rect;
    scroll_texture_luz0_rect.x = 0;
    scroll_texture_luz0_rect.y = 456;
    scroll_texture_luz0_rect.w = 928;
    scroll_texture_luz0_rect.h = 165;
    scrolling_tex_al.construct(scrolling_textures+number_of_scrollingTex,"Layer_0007_Lights.png",4 ,4,scroll_texture_luz0_rect,&game_renderer.get_renderer());
    pixel_coord coords7;
    coords7.x =  0;
    coords7.y =  0;
    (scrolling_textures+number_of_scrollingTex)->set_pos(coords7);
    ++number_of_scrollingTex; //7




    ////////////////////////////////////////COLLIDERS CREATION////////////////////////////////////////
    float b2_coords_scale_x = right_b2_screen_coord - left_b2_screen_coord;
    float b2_coords_scale_y = top_b2_screen_coord - bottom_b2_screen_coord;

    uint16 character_mask = 1;
    uint16 ground_mask    = 2;
    uint16 obstacles_mask = 4;



    //SUELO

    pixel_coord ground_sprite_size;

    ground_sprite_size.x = suelo_texture_rect.w * ground_scale_x + screen_size.x/2;
    ground_sprite_size.y = screen_size.y/2 - suelo_texture_rect.h*ground_scale_y;
    b2Vec2 real_ground_size = physics_world.pixel_to_b2Vec(ground_sprite_size);

    b2Vec2 real_ground_pos(0,bottom_b2_screen_coord-0.2f);


    b2Filter ground_filter;
    ground_filter.categoryBits = ground_mask;
    ground_filter.maskBits     = character_mask;

    ground_object = new Static_Physic_Object(physics_world,real_ground_size,real_ground_pos,ground_filter,TERRAIN_ENTITY_TYPE);

    //Cabeza
    b2Filter obstacle_filter;
    obstacle_filter.categoryBits = obstacles_mask;
    obstacle_filter.maskBits     = character_mask;

    obstacle_0 = new Obstacle_Controller(obstacles_sprites,physics_world,obstacle_filter);
    obstacle_0->set_vel(pixel_coord(-600,0));

    b2Filter player_filter;
    player_filter.categoryBits = character_mask;
    player_filter.maskBits     = ground_mask | obstacles_mask;


    player = new Character_Controller(physics_world,game_renderer,player_filter);

    game_renderer.attach_rendereable(*(scrolling_textures+1));
    game_renderer.attach_rendereable(*(scrolling_textures+4));
    game_renderer.attach_rendereable(*(scrolling_textures+2));
    game_renderer.attach_rendereable(*(scrolling_textures+6));
    game_renderer.attach_rendereable(*(scrolling_textures+3));
    game_renderer.attach_rendereable(player->get_sprite());
    game_renderer.attach_rendereable(*scrolling_textures);
    game_renderer.attach_rendereable(*(scrolling_textures+5));
    game_renderer.attach_rendereable(*obstacles_sprites);

    animation_handler.Attach_Character(player);
    animation_handler.Attach_Obstacle(obstacle_0);
    animation_handler.Attach_ScrollingTex(scrolling_textures+1,0.0001f);
    animation_handler.Attach_ScrollingTex(scrolling_textures+4,0.0002f);
    animation_handler.Attach_ScrollingTex(scrolling_textures+2,0.0003f);
    animation_handler.Attach_ScrollingTex(scrolling_textures+6,0.0004f);
    animation_handler.Attach_ScrollingTex(scrolling_textures+3,0.0005f);
    animation_handler.Attach_ScrollingTex(scrolling_textures,  0.0005f);
    animation_handler.Attach_ScrollingTex(scrolling_textures+5,0.0006f);

    Obstacle_Stats cabeza_stats(50);
    obstacle_handler.Attach_Obstacle(obstacle_0,cabeza_stats);
}

