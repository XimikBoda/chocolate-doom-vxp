#include "SDL_events.h"
#include <vmio.h>
#include "vmsys.h"

#include "thread.h"

#define QUEUE_SIZE 16

static SDL_Event queue[QUEUE_SIZE];
static int queueWriteIndex = 0;
static int queueReadIndex = 0;

static void addEvent(SDL_Event event)
{
    if (queueWriteIndex + 1 % QUEUE_SIZE == queueReadIndex)
        return;

    queue[queueWriteIndex++] = event;
    queueWriteIndex %= QUEUE_SIZE;
}

void SDL_PumpEvents(void) {}

int SDL_PeepEvents(SDL_Event *events, int numevents, SDL_eventaction action, Uint32 minType, Uint32 maxType) {
    return -1;
}

int SDL_PollEvent(SDL_Event *event) {
    if (!event)
        return queueWriteIndex != queueReadIndex;

    if(queueWriteIndex == queueReadIndex)
        return 0;
    else {
        *event = queue[queueReadIndex++];
        queueReadIndex %= QUEUE_SIZE;
        return 1;
    }
}

int SDL_WaitEvent(SDL_Event *event) {
    thread_next();
    return SDL_PollEvent(event);
}

static SDL_Event keyevt_to_sdlevent(VMINT event, VMINT keycode) {
    SDL_Event ev = {0}; 
    switch (event)
    {
        case VM_KEY_EVENT_UP:
            ev.type = SDL_KEYUP;
            ev.key.state = SDL_RELEASED;
            break;
        case VM_KEY_EVENT_REPEAT:
        case VM_KEY_EVENT_LONG_PRESS:
            ev.key.repeat = SDL_TRUE;
        case VM_KEY_EVENT_DOWN:
            ev.type = SDL_KEYDOWN;
            ev.key.state = SDL_PRESSED;
            break;
    }

    switch (keycode)
    {
        case VM_KEY_UP:
            ev.key.keysym.scancode = SDL_SCANCODE_LEFT;
            break;
        case VM_KEY_RIGHT:
            ev.key.keysym.scancode = SDL_SCANCODE_UP;
            break;
        case VM_KEY_DOWN:
            ev.key.keysym.scancode = SDL_SCANCODE_RIGHT;
            break;
        case VM_KEY_LEFT:
            ev.key.keysym.scancode = SDL_SCANCODE_DOWN;
            break;
        case VM_KEY_OK:
            ev.key.keysym.scancode = SDL_SCANCODE_RETURN;
            break;
        case VM_KEY_LEFT_SOFTKEY:
            ev.key.keysym.scancode = SDL_SCANCODE_RCTRL;
            break;
        case VM_KEY_NUM2:
            ev.key.keysym.scancode = SDL_SCANCODE_SPACE;
            break;
        case VM_KEY_RIGHT_SOFTKEY:
            ev.key.keysym.scancode = SDL_SCANCODE_ESCAPE;
            break;
    }

    return ev;
}

void handle_keyevt(VMINT event, VMINT keycode) {
    addEvent(keyevt_to_sdlevent(event, keycode));
}