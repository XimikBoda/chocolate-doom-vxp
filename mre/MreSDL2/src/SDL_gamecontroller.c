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

const char* SDL_GameControllerName(SDL_GameController *gamecontroller) {
    return NULL;
}

int SDL_GameControllerEventState(int state){
    return state;
}

Sint16 SDL_GameControllerGetAxis(SDL_GameController *gamecontroller, SDL_GameControllerAxis axis) {
    return 0;
}

Uint8 SDL_GameControllerGetButton(SDL_GameController *gamecontroller, SDL_GameControllerButton button) {
    return 0;
}

void SDL_GameControllerClose(SDL_GameController *gamecontroller){}