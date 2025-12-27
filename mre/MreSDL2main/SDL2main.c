#include <vmsys.h>
#include <vmgraph.h>

#include <console.h>

VMINT layer_hdl[1];
VMUINT16 *scr_buf = 0;

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
    vm_graphic_flush_layer(layer_hdl, 1);

    const char *argv[2] = {"", "-version"};
#ifdef WIN32
    SDL_main(2, &argv);
#else
    main(2, &argv);
#endif // WIN32
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

