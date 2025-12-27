#include "SDL_joystick.h"

int SDL_NumJoysticks(void) {
    return 0;
}

const char* SDL_JoystickNameForIndex(int device_index) {
    return "";
}

const char *SDL_JoystickPathForIndex(int device_index) {
    return "";
}

int SDL_JoystickGetDevicePlayerIndex(int device_index) {
    return -1;
}

SDL_JoystickGUID SDL_JoystickGetDeviceGUID(int device_index) {
    SDL_JoystickGUID guid = {0};
    return guid;
}

Uint16 SDL_JoystickGetDeviceVendor(int device_index) {
    return 0;
}

Uint16 SDL_JoystickGetDeviceProduct(int device_index) {
    return 0;
}

Uint16 SDL_JoystickGetDeviceProductVersion(int device_index) {
    return 0;
}

SDL_JoystickType SDL_JoystickGetDeviceType(int device_index) {
    return SDL_JOYSTICK_TYPE_UNKNOWN;
}

SDL_JoystickID SDL_JoystickGetDeviceInstanceID(int device_index) {
    return -1;
}

SDL_Joystick *SDL_JoystickOpen(int device_index) {
    return NULL;
}

SDL_Joystick* SDL_JoystickFromInstanceID(SDL_JoystickID instance_id) {
    return NULL;
}

SDL_Joystick* SDL_JoystickFromPlayerIndex(int player_index) {
    return NULL;
}

int SDL_JoystickAttachVirtual(SDL_JoystickType type, int naxes, int nbuttons, int nhats) {
    return -1;
}

int SDL_JoystickAttachVirtualEx(const SDL_VirtualJoystickDesc *desc) {
    return -1;
}

int SDL_JoystickDetachVirtual(int device_index) {
    return -1;
}

SDL_bool SDL_JoystickIsVirtual(int device_index) {
    return SDL_FALSE;
}

int SDL_JoystickSetVirtualAxis(SDL_Joystick *joystick, int axis, Sint16 value) {
    return -1;
}

int SDL_JoystickSetVirtualButton(SDL_Joystick *joystick, int button, Uint8 value) {
    return -1;
}

int SDL_JoystickSetVirtualHat(SDL_Joystick *joystick, int hat, Uint8 value) {
    return -1;
}

const char* SDL_JoystickName(SDL_Joystick *joystick) {
    return NULL;
}

const char* SDL_JoystickPath(SDL_Joystick *joystick) {
    return NULL;
}

int SDL_JoystickGetPlayerIndex(SDL_Joystick *joystick) {
    return -1;
}

void SDL_JoystickSetPlayerIndex(SDL_Joystick *joystick, int player_index) {}

SDL_JoystickGUID SDL_JoystickGetGUID(SDL_Joystick *joystick) {
    SDL_JoystickGUID guid = {0};
    return guid;
}

Uint16 SDL_JoystickGetVendor(SDL_Joystick *joystick) {
    return 0;
}

Uint16 SDL_JoystickGetProduct(SDL_Joystick *joystick) {
    return 0;
}

Uint16 SDL_JoystickGetProductVersion(SDL_Joystick *joystick) {
    return 0;
}

Uint16 SDL_JoystickGetFirmwareVersion(SDL_Joystick *joystick) {
    return 0;
}

const char* SDL_JoystickGetSerial(SDL_Joystick *joystick) {
    return NULL;
}

SDL_JoystickType SDL_JoystickGetType(SDL_Joystick *joystick) {
    return SDL_JOYSTICK_TYPE_UNKNOWN;
}

void SDL_JoystickGetGUIDString(SDL_JoystickGUID guid, char *pszGUID, int cbGUID) {
    if (pszGUID)
        pszGUID[0] = 0;
}

SDL_JoystickGUID SDL_JoystickGetGUIDFromString(const char *pchGUID) {
    SDL_JoystickGUID guid = {0};
    return guid;
}

void SDL_GetJoystickGUIDInfo(SDL_JoystickGUID guid, Uint16 *vendor, Uint16 *product, Uint16 *version, Uint16 *crc16) {
    *vendor = 0;
    *product = 0;
    *version = 0;
    *crc16 = 0;
}

SDL_bool SDL_JoystickGetAttached(SDL_Joystick *joystick) {
    return SDL_FALSE;
}

SDL_JoystickID SDL_JoystickInstanceID(SDL_Joystick *joystick) {
    return -1;
}

int SDL_JoystickNumAxes(SDL_Joystick *joystick) {
    return -1;
}

int SDL_JoystickNumBalls(SDL_Joystick *joystick) {
    return -1;
}

int SDL_JoystickNumHats(SDL_Joystick *joystick) {
    return -1;
}

int SDL_JoystickNumButtons(SDL_Joystick *joystick) {
    return -1;
}

void SDL_JoystickUpdate(void) {}

int SDL_JoystickEventState(int state) {
    return 0;
}

Sint16 SDL_JoystickGetAxis(SDL_Joystick *joystick, int axis) {
    return 0;
}

SDL_bool SDL_JoystickGetAxisInitialState(SDL_Joystick *joystick, int axis, Sint16 *state) {
    return SDL_FALSE;
}

Uint8 SDL_JoystickGetHat(SDL_Joystick *joystick, int hat) {
    return SDL_HAT_CENTERED;
}

int SDL_JoystickGetBall(SDL_Joystick *joystick, int ball, int *dx, int *dy) {
    *dx = 0;
    *dy = 0;
    return -1;
}

Uint8 SDL_JoystickGetButton(SDL_Joystick *joystick, int button) {
    return 0;
}

int SDL_JoystickRumble(SDL_Joystick *joystick, Uint16 low_frequency_rumble, Uint16 high_frequency_rumble, Uint32 duration_ms) {
    return -1;
}

int SDL_JoystickRumbleTriggers(SDL_Joystick *joystick, Uint16 left_rumble, Uint16 right_rumble, Uint32 duration_ms) {
    return -1;
}

SDL_bool SDL_JoystickHasLED(SDL_Joystick *joystick) {
    return SDL_FALSE;
}

SDL_bool SDL_JoystickHasRumble(SDL_Joystick *joystick) {
    return SDL_FALSE;
}

SDL_bool SDL_JoystickHasRumbleTriggers(SDL_Joystick *joystick) {
    return SDL_FALSE;
}

int SDL_JoystickSetLED(SDL_Joystick *joystick, Uint8 red, Uint8 green, Uint8 blue) {
    return -1;
}

int SDL_JoystickSendEffect(SDL_Joystick *joystick, const void *data, int size) {
    return -1;
}

void SDL_JoystickClose(SDL_Joystick *joystick) {}

SDL_JoystickPowerLevel SDL_JoystickCurrentPowerLevel(SDL_Joystick* joystick) {
    return SDL_JOYSTICK_POWER_UNKNOWN;
}
