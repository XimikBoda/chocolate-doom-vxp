#include "SDL_filesystem.h"

#include <stdio.h>

char *SDL_GetPrefPath(const char *org, const char *app) {
    char *path = SDL_malloc(100);
    sprintf(path, "e:\\doom\\%s", app);
    return path;
}