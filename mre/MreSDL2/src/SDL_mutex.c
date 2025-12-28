#include "SDL_mutex.h"

SDL_mutex* SDL_CreateMutex(void) {
    return NULL;
}

int SDL_LockMutex(SDL_mutex *mutex) {
    return 0;
}

int SDL_UnlockMutex(SDL_mutex *mutex) {
    return 0;
}

void SDL_DestroyMutex(SDL_mutex *mutex) {}

SDL_cond* SDL_CreateCond(void) {
    return 0;
}

void SDL_DestroyCond(SDL_cond *cond) {}

int SDL_CondSignal(SDL_cond *cond) {
    return -1;
}

int SDL_CondWait(SDL_cond *cond, SDL_mutex *mutex) {
    return -1;
}