#include "SDL_stdinc.h"
#include <vmsys.h>

void *SDL_malloc(size_t size) {
    return vm_malloc(size);
}

void *SDL_calloc(size_t nmemb, size_t size) {
    return vm_calloc(nmemb * size);

}

void* SDL_realloc(void *mem, size_t size) {
    if (mem)
        return vm_realloc(mem, size);
    else
        return vm_malloc(size);
}

void SDL_free(void *mem) {
    vm_free(mem);
}

void SDL_qsort(void *base, size_t nmemb, size_t size, SDL_CompareCallback compare) {
    void *temp_mem = SDL_malloc(nmemb);

    for (int i = 0; i < size - 1; ++i) // yes "qsort"
        for (int j = i + 1; j < size; ++j) {
            void *a = (const char *) base + i * nmemb;
            void *b = (const char *) base + j * nmemb;
            if (compare(a, b)) 
            {
                SDL_memcpy(temp_mem, a, nmemb);
                SDL_memcpy(a, b, nmemb);
                SDL_memcpy(b, temp_mem, nmemb);
            }
        }

    SDL_free(temp_mem);
}

void* SDL_memcpy(SDL_OUT_BYTECAP(len) void *dst, SDL_IN_BYTECAP(len) const void *src, size_t len) {
    memcpy(dst, src, len);
}