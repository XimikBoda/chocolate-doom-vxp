#include <vmsys.h>

extern void __main(void);
void pre_vm_main();
void vm_main_posix();

int atexit(void (*func)(void)) {
    return 0;
}

int DllMainCRTStartup(int hinstDLL, int fdwReason, int lpvReserved) {
    return TRUE;
}

void vm_main() {
    pre_vm_main();
    __main();
    vm_main_posix();
}