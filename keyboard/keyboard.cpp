#include "SDL3/SDL.h"
#include <iostream>
#include <string>
#include "keyboard.h"
/* turn this into a class? */
/* static all that call it should have same instance */
/* we need to make this thread safe */


/** handle key press */
SDL_AppResult handle_key_event(SDL_Scancode key_code){
    switch (key_code)
    {
    case SDL_SCANCODE_ESCAPE:
    case SDL_SCANCODE_Q:
        return SDL_APP_SUCCESS;
    
    /* directions of user */
    case SDL_SCANCODE_RIGHT:
        SDL_Log("user pressed right arrow");
        break;
    case SDL_SCANCODE_UP:
        SDL_Log("user pressed up arrow");
        break;
    case SDL_SCANCODE_LEFT:
        SDL_Log("user pressed left arrow");
        break;
    case SDL_SCANCODE_DOWN:
        SDL_Log("user pressed down arrow");
        break;

    default:
        break;
    }

    return SDL_APP_CONTINUE;
}