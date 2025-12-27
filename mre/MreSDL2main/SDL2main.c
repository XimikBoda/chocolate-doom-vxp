#include <vmsys.h>
#include <vmgraph.h>
#include <vmio.h>

#include <console.h>

#include "thread.h"

VMINT layer_hdl[1];
VMUINT16 *scr_buf = 0;

void handle_keyevt(VMINT event, VMINT keycode);

void thread()
{
    thread_next();

    const char *argv[1] = {"e:\\doom.exe"};
#ifdef WIN32
    SDL_main(1, &argv);
#else
    main(1, &argv);
#endif // WIN32
}

void timer(int tid)
{
    thread_next();
}

void pre_vm_main()
{
    VMINT screen_w = vm_graphic_get_screen_width();
    VMINT screen_h = vm_graphic_get_screen_height();

    layer_hdl[0] = vm_graphic_create_layer(0, 0, screen_w, screen_h, -1);
    scr_buf = (VMUINT16*) vm_graphic_get_layer_buffer(layer_hdl[0]);
    vm_graphic_set_clip(0, 0, screen_w, screen_h);

    console_init(screen_w, screen_h);
}

void vm_main_posix()
{
    vm_kbd_set_mode(VM_KEYPAD_2KEY_NUMBER);
    vm_reg_keyboard_callback(handle_keyevt);

    thread_init();
    thread_create(1024 * 1024, thread);

    vm_create_timer(1, timer);
}

void flush_layer() {
    vm_graphic_flush_layer(layer_hdl, 1);
}


#ifdef WIN32
void vm_main()
{
    pre_vm_main();
    vm_main_posix();
}
#endif // WIN32

