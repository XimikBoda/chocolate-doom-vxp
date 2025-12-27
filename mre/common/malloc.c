#include <vmsys.h>
#include <sys/types.h>

void* malloc(size_t size) {
    return vm_malloc(size);
}

void* calloc(size_t number, size_t size) {
    return vm_calloc(size * number);
}

void* realloc(void* ptr, size_t newsize) {
    if (ptr)
        return vm_realloc(ptr, newsize);
    else
        return vm_malloc(newsize);
}

void free(void* ptr) {
    vm_free(ptr);
}

void* _malloc_r(struct _reent *reent_ptr, size_t size) {
    return malloc(size);
}

void* _calloc_r(struct _reent *reent_ptr, size_t number, size_t size) {
    return calloc(number, size);
}

void* _realloc_r(struct _reent *reent_ptr, void* ptr, size_t newsize) {
    return realloc(ptr, newsize);
}

void _free_r(struct _reent *reent_ptr, void* ptr) {
    vm_free(ptr);
}