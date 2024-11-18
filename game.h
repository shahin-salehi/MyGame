#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <SDL3/SDL.h>

typedef struct {
    std::string name;
    int xpos;
    int ypos;
} PlayerContext; 

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    PlayerContext player_context;
} AppState;



#endif