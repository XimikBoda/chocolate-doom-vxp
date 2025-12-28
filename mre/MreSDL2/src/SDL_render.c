#include "SDL_render.h"

#include "thread.h"

#define ROTATED

static const char *dummy = ""; 

SDL_Renderer* SDL_CreateRenderer(SDL_Window *window, int index, Uint32 flags){
    return (SDL_Renderer*)dummy;
}

int SDL_GetRendererInfo(SDL_Renderer *renderer, SDL_RendererInfo *info) {
    if (!info)
        return -1;

    info->name = dummy;
    info->flags = SDL_RENDERER_SOFTWARE;
    info->num_texture_formats = 1;
    info->texture_formats[0] = 16;
    info->max_texture_width = vm_graphic_get_screen_height();
    info->max_texture_height = vm_graphic_get_screen_width();

    return 0;
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

void SDL_RenderPresent(SDL_Renderer *renderer) {
    flush_layer();
    thread_next();
}

void SDL_DestroyTexture(SDL_Texture *texture) {}

void SDL_DestroyRenderer(SDL_Renderer *renderer) {}