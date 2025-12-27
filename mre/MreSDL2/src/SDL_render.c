#include "SDL_render.h"

#define ROTATED

static const char *dummy = ""; 

SDL_Renderer* SDL_CreateRenderer(SDL_Window *window, int index, Uint32 flags){
    return (SDL_Renderer*)dummy;
}

int SDL_GetRendererOutputSize(SDL_Renderer *renderer, int *w, int *h) {
#ifndef ROTATED
    *w = vm_graphic_get_screen_width();
    *h = vm_graphic_get_screen_height();
#else
    *h = vm_graphic_get_screen_width();
    *w = vm_graphic_get_screen_height();
#endif
    return 0;
}

SDL_Texture* SDL_CreateTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface){
    return (SDL_Texture*)dummy;
}

int SDL_RenderClear(SDL_Renderer *renderer) {
    return 0;
}

int SDL_RenderCopy(SDL_Renderer *renderer, SDL_Texture *texture,
                   const SDL_Rect *srcrect, const SDL_Rect *dstrect) {
    return 0;
}

void SDL_RenderPresent(SDL_Renderer *renderer){}

void SDL_DestroyTexture(SDL_Texture *texture) {}

void SDL_DestroyRenderer(SDL_Renderer *renderer) {}