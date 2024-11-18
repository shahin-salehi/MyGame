#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <string>
#include "SDL3/SDL.h"
#include "../game.h"

SDL_AppResult handle_key_event(SDL_Scancode key_code, AppState *as);

#endif