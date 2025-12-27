#include "SDL_keyboard.h"

SDL_Keymod SDL_GetModState(void) {
    return KMOD_NONE;
}

SDL_Keycode SDL_GetKeyFromScancode(SDL_Scancode scancode) {
    return 0;
}

const char* SDL_GetKeyName(SDL_Keycode key) {
    return "";
};

void SDL_StartTextInput(void) {}

SDL_bool SDL_IsTextInputActive(void) {
    return SDL_FALSE;
}

void SDL_StopTextInput(void) {}