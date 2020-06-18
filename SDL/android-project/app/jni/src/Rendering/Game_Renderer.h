//
// Created by migue on 17/01/2020.
//

#ifndef ANDROID_PROJECT_GAME_RENDERER_H
#define ANDROID_PROJECT_GAME_RENDERER_H

#include <SDL.h>
#include <SDL_image.h>
#include "Rendereable.h"

#define  MAX_RENDEREABLES 100

struct Render_Queue_Objecct{
    Rendereable* rendereable;
    bool         is_able;
    unsigned int queue_index;
};
class Game_Renderer {
    SDL_Renderer* renderer;
    Render_Queue_Objecct  render_objects[MAX_RENDEREABLES];
    unsigned int number_of_redereables;
public:
    Game_Renderer(SDL_Renderer* renderer);
    void render();
    ///Añade un Rendereable a la cola de render
    ///Devuelve una referencia a la posición en la cola de render
    const unsigned int& attach_rendereable(Rendereable& rendereable);
    ///Desactiva un item de la cola de render pero no lo elimina de esta
    void set_disable(Rendereable& rendereable);
    ///Activa un item de la cola de render pero no lo elimina de esta
    void set_able(Rendereable&    rendereable);
    ///Devuelve la posición en cola del objeto
    const unsigned int& get_render_queue_index(Rendereable& rendereable);
    ///Desactiva un item de la cola de render pero no lo elimina de esta
    void set_disable(unsigned int render_queue_index);
    ///Activa un item de la cola de render pero no lo elimina de esta
    void set_able(unsigned  int render_queue_index);
    ///Elimina un item de la cola de render y mueve los elementos necesarios y actualiza su index
    ///No se recomienda hacer esto en tiempo de juego
    void deattach_rendereable(Rendereable& rendereable);
    ///No se recomienda hacer esto en tiempo de juego
    void deattach_rendereable(unsigned  int render_queue_index);
    ///Devuelve el renderer usado
    SDL_Renderer& get_renderer();
    pixel_coord   get_SCREEN_SIZE();
};


#endif //ANDROID_PROJECT_GAME_RENDERER_H
