#include "SDL_gamecontroller.h"

char* SDL_GameControllerMappingForGUID(SDL_JoystickGUID guid) {
    return NULL;
}

SDL_bool SDL_IsGameController(int joystick_index) {
    return SDL_FALSE;
}

SDL_GameControllerType SDL_GameControllerTypeForIndex(int joystick_index) {
    return SDL_CONTROLLER_TYPE_UNKNOWN;
}

SDL_GameController* SDL_GameControllerOpen(int joystick_index) {
    return NULL;
}

int SDL_GameControllerEventState(int state){
    return state;
}

void SDL_GameControllerClose(SDL_GameController *gamecontroller){}