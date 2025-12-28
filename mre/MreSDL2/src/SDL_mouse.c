#include "SDL_mouse.h"

Uint32 SDL_GetMouseState(int *x, int *y) {
    if (!x || !y)
        return 0;
    *x = 0;
    *y = 0;
    return 0;
}

Uint32 SDL_GetRelativeMouseState(int *x, int *y) {
    if (!x || !y)
        return 0;
    *x = 0;
    *y = 0;
    return 0;
}

void SDL_WarpMouseInWindow(SDL_Window *window, int x, int y) {}

int SDL_SetRelativeMouseMode(SDL_bool enabled) {
    return -1;
}