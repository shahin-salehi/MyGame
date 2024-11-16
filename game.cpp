/*   https://wiki.libsdl.org/SDL3/README/main-functions  */

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
// this allows us to follow a different main pattern that helps with init, iterate, and finish
#include <SDL3/SDL.h>
#include <iostream>

/*  Define window variables */
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
// static ties these variables only to this file and not others who inherit it
static const int width = 640;
static const int height = 480;

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

    if (!SDL_CreateWindowAndRenderer("Shahin's Game", width, height, 0, &window, &renderer)){
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

/*
* Handles our events such as mouseclick, keypress etc. 
 */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
    //check quit event
    if (event->type == SDL_EVENT_QUIT){
        return SDL_APP_SUCCESS; /* end the program, report success to OS */
    }
    return SDL_APP_CONTINUE; /* carry on with program*/
}

/*
* Main function, heart of the program. Called as often as possible,
* hopefully at the refreshrate of the program that has been decided. 
*/
SDL_AppResult SDL_AppIterate(void *appstate){
    const double now = ((double)SDL_GetTicks()) / 1000.0;
    /* choose the color the frame will draw. The sine wave trick makes it fade smoothly*/
    const float red = (float) (0.5 + 0.5 * SDL_sin(now));
    const float green = (float) (0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2/3)); 
    const float blue = (float) (0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4/3));

    /* Takes pointer to renderer and colors it with our defined colors  */
    SDL_SetRenderDrawColorFloat(renderer, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT); 

    /* clear the window. */
    SDL_RenderClear(renderer);

    /* Update screen with any rendering performed since previous call */
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;

}

/* Runs once at shutdown
*
* from documentation: ...if it returns SDL_APP_FAILURE, SDL will call SDL_AppQuit
* I assume this name is reserved and SDL will call it if any function returns the app failure code
*/
void SDL_AppQuit(void *appstate, SDL_AppResult result){
    /* SDL will clean up for us */
}