#include "SDL_timer.h"
#include "vmsys.h"

Uint32 SDL_GetTicks(void){
    return vm_get_tick_count();
}

void SDL_Delay(Uint32 ms){
    //todo
}