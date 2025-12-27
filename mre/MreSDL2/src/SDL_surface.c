#include "SDL_surface.h"

static const char *dummy = "";

SDL_Surface* SDL_CreateRGBSurface(Uint32 flags, int width, int height,
    int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) 
{
    return (SDL_Surface*)dummy;
}

SDL_Surface* SDL_CreateRGBSurfaceFrom(
    void *pixels, int width, int height, int depth, int pitch, Uint32 Rmask,
    Uint32 Gmask, Uint32 Bmask, Uint32 Amask)
{
    return (SDL_Surface *) dummy;
}

void SDL_FreeSurface(SDL_Surface *surface) {}

int SDL_LockSurface(SDL_Surface *surface) {
    return 0;
}

void SDL_UnlockSurface(SDL_Surface *surface) {}