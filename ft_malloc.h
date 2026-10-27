#ifndef FT_MALLOC_H
    #define FT_MALLOC_H

    #include <sys/mman.h>
    #include <sys/resource.h>
    #include <unistd.h>
    #include <sys/syscall.h>
    #include <stdint.h>
    #define PAGESIZE sysconf(_SC_PAGESIZE)
    typedef intptr_t sptr;
    typedef uintptr_t uptr;
    typedef struct block {
        size_t size;
        bool free;
        struct block *next_block;
    } d_block;
#endif