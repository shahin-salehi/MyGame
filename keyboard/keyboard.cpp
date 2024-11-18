#include "SDL3/SDL.h"
#include <iostream>
#include <string>
#include "keyboard.h"
/* turn this into a class? */
/* static all that call it should have same instance */
/* we need to make this thread safe */


/** handle key press */
SDL_AppResult handle_key_event(SDL_Scancode key_code, AppState *as){
    SDL_Log("Player position: x[%d] - y[%d]", as->player_context.xpos, as->player_context.ypos);
    switch (key_code)
    {
   
    case SDL_SCANCODE_ESCAPE:
    case SDL_SCANCODE_Q:
        return SDL_APP_SUCCESS;
    
    /* directions of user */
    case SDL_SCANCODE_RIGHT:
        if (as->player_context.xpos < as->window_width -10){
            as->player_context.xpos +=10;
        }
        break;
    case SDL_SCANCODE_UP:
        if (as->player_context.ypos > 0){
            as->player_context.ypos -=10;
        }
        break;
    case SDL_SCANCODE_LEFT:
        if (as->player_context.xpos > 0){
            as->player_context.xpos -=10;
        }
        break;
    case SDL_SCANCODE_DOWN: 
        if (as->player_context.ypos < as->window_height -10){
            as->player_context.ypos +=10;
        }
        break;
    default:
        break;
    }

    return SDL_APP_CONTINUE;
}