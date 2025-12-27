#include <stdio.h>
#include "vmsys.h"
#include "vmchset.h"
#include "vmlog.h"
#include "vmio.h"
#include "vmstdlib.h"

extern unsigned int __init_array_start;
extern unsigned int __init_array_end;

typedef VMINT(*vm_get_sym_entry_t)(char* symbol);
vm_get_sym_entry_t vm_get_sym_entry;
typedef void (**__init_array) (void);

int __g_errno = 0;

void pre_vm_main();
void vm_main_posix();

void gcc_entry(unsigned int entry, unsigned int init_array_start, unsigned int count)
{
	unsigned int i;
	__init_array ptr;
	vm_get_sym_entry = (vm_get_sym_entry_t)entry;

	pre_vm_main();

	if (init_array_start == 0)
		init_array_start = (unsigned int)&__init_array_start,
		count = ((unsigned int)&__init_array_end - (unsigned int)&__init_array_start) / 4;

	ptr = (__init_array)init_array_start;
	for (i = 0; i < count; i++)
	{
		ptr[i]();
	}
	vm_main_posix();
}
