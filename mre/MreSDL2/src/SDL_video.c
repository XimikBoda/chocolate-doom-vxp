#include "SDL_video.h"
#include "vmgraph.h"

#define ROTATED

static const char *dummy = ""; 

int SDL_GetNumVideoDisplays(void) {
    return 1;
}

int SDL_GetDisplayBounds(int displayIndex, SDL_Rect *rect) {
    if (!rect)
        return -1;

    rect->x = 0;
    rect->y = 0;

    rect->h = vm_graphic_get_screen_width();
    rect->w = vm_graphic_get_screen_height();

    return 0;
}

int SDL_GetWindowDisplayIndex(SDL_Window *window) {
    return 1;
}

Uint32 SDL_GetWindowFlags(SDL_Window *window) {
    return 0;
}

Uint32 SDL_GetWindowID(SDL_Window *window) {
    return 0;
}

void SDL_SetWindowTitle(SDL_Window * window, const char *title){}

void SDL_SetWindowIcon(SDL_Window * window, SDL_Surface * icon){}

int SDL_GetCurrentDisplayMode(int displayIndex, SDL_DisplayMode *mode){
    mode->format = 16;

#ifndef ROTATED
    mode->w = vm_graphic_get_screen_width();
    mode->h = vm_graphic_get_screen_height();
#else
    mode->h = vm_graphic_get_screen_width();
    mode->w = vm_graphic_get_screen_height();
 #endif

    mode->refresh_rate = 30;
    mode->driverdata = NULL;

    return 0;
}

SDL_Window* SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags){
    return (SDL_Window *) dummy;
}

void SDL_SetWindowSize(SDL_Window *window, int w, int h) {}

void SDL_GetWindowSize(SDL_Window *window, int *w, int *h) {
#ifndef ROTATED
    *w = vm_graphic_get_screen_width();
    *h = vm_graphic_get_screen_height();
#else
    *h = vm_graphic_get_screen_width();
    *w = vm_graphic_get_screen_height();
#endif
}

int SDL_SetWindowFullscreen(SDL_Window *window, Uint32 flags) {
    return -1;
}

void SDL_DestroyWindow(SDL_Window *window){}