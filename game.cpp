/*   https://wiki.libsdl.org/SDL3/README/main-functions  */

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
// this allows us to follow a different main pattern that helps with init, iterate, and finish
#include <SDL3/SDL.h>
#include "keyboard/keyboard.h"
#include <iostream>
#include <string>

/*  Define window variables */
//static SDL_Window *window = NULL;
//static SDL_Renderer *renderer = NULL;
// static ties these variables only to this file and not others who inherit it
static const int width = 1080;
static const int height = 720;

/*
* This program runs once at startup 
*/
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){
    if (!SDL_SetAppMetadata("Shahin's Game", "0.1", "first attempt")) {
        return SDL_APP_FAILURE;
    }

    /* learn how these flags work*/
    if (!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    /* appstate */
    AppState *as = new AppState;
    if(!as){
        return SDL_APP_FAILURE;
    }
    // point appstate to our appstate
    *appstate = as;

    if (!SDL_CreateWindowAndRenderer("Shahin's Game", width, height, 0, &as->window, &as->renderer)){
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // Init our character
    as->player_context = {"shahin", 250, 250};
    as->player_context.h = 10;
    as->player_context.w = 10;

    return SDL_APP_CONTINUE;
}

/*
* Handles our events such as mouseclick, keypress etc. 
 */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
    // cast
    AppState *as = static_cast<AppState*>(appstate);

    //check quit event
    if (event->type == SDL_EVENT_QUIT){
        return SDL_APP_SUCCESS; /* end the program, report success to OS */
    }
    if (event->type == SDL_EVENT_KEY_DOWN){
        return handle_key_event(event->key.scancode, as);
    }
    return SDL_APP_CONTINUE; /* carry on with program*/
}

/*
* Main function, heart of the program. Called as often as possible,
* hopefully at the refreshrate of the program that has been decided. 
*/
SDL_AppResult SDL_AppIterate(void *appstate){
    /* get state caste from void to our type */
    AppState *as = static_cast<AppState*>(appstate);
    SDL_FRect r;

    /* clear the window. */
    SDL_RenderClear(as->renderer);

    /* draw background color */
    SDL_SetRenderDrawColor(as->renderer, 255, 255, 255, 255);

    /* draw our character */
    // first draw color
    // then position it
    r.h = as->player_context.h;
    r.w = as->player_context.w;
    r.x = as->player_context.xpos;
    r.y = as->player_context.ypos;
    SDL_RenderFillRect(as->renderer, &r);    
    
    /* now draw background */
    SDL_SetRenderDrawColor(as->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    /* Update screen with any rendering performed since previous call */
    SDL_RenderPresent(as->renderer);

    return SDL_APP_CONTINUE;

}

/* Runs once at shutdown
*
* from documentation: ...if it returns SDL_APP_FAILURE, SDL will call SDL_AppQuit
* I assume this name is reserved and SDL will call it if any function returns the app failure code
*/
void SDL_AppQuit(void *appstate, SDL_AppResult result){
    /* SDL will clean up for us */

    /* delete allocated appstate */
    AppState *as = static_cast<AppState*>(appstate);
    delete as;
}