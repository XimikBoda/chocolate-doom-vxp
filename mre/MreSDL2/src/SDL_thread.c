#include "SDL_thread.h"

#undef SDL_CreateThread
SDL_Thread *SDL_CreateThread(SDL_ThreadFunction fn, const char *name, void *data)
{
    return NULL;
}

void SDL_WaitThread(SDL_Thread *thread, int *status) {}