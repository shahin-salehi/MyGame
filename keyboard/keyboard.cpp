#include "SDL3/SDL.h"
#include <iostream>
#include <string>
#include "keyboard.h"
/* turn this into a class? */
/* static all that call it should have same instance */
/* we need to make this thread safe */


/** handle key press */
SDL_AppResult handle_key_event(SDL_Scancode key_code, AppState *as){
    switch (key_code)
    {
    case SDL_SCANCODE_ESCAPE:
    case SDL_SCANCODE_Q:
        return SDL_APP_SUCCESS;
    
    /* directions of user */
    case SDL_SCANCODE_RIGHT:
        as->player_context.xpos +=10;
        break;
    case SDL_SCANCODE_UP:
        as->player_context.ypos -=10;
        break;
    case SDL_SCANCODE_LEFT:
        as->player_context.xpos -=10;
        break;
    case SDL_SCANCODE_DOWN: 
        as->player_context.ypos +=10;
        break;

    default:
        break;
    }

    return SDL_APP_CONTINUE;
}