#include "Game_Logic/Game.h"
#include <stdexcept>
#include <android/log.h>

int main(int argc, char* argv[]) {


    Game my_game(640,480);
    my_game.Start_Game_Loop();
    return 0;
}
/*
 * SDL_Window *window;
 * SDL_Renderer* renderer
 * myb2_World my_world;
 */
