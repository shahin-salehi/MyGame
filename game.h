#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <SDL3/SDL.h>

typedef struct {
    std::string name;
    int xpos;
    int ypos;
    int h;
    int w;
    int offset;
} PlayerContext; 

typedef struct {
    bool is_food;
    int xpos;
    int ypos;
} Food;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int window_width;
    int window_height;
    PlayerContext player_context;
    Food food;
} AppState;



#endif