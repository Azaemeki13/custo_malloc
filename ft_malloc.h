#ifndef FT_MALLOC_H
    #define FT_MALLOC_H

    #include <sys/mman.h>
    #include <sys/resource.h>
    #include <unistd.h>
    #include <sys/syscall.h>
    #include <stdint.h>
    #define PAGESIZE sysconf(_SC_PAGESIZE)
    #define TINY PAGESIZE
    #define SMALL PAGESIZE*2
    #define LARGE PAGESIZE*4
    typedef intptr_t sptr;
    typedef uintptr_t uptr;

    enum warning {
        NOEXIST,
        FULL,
        OK
    };
    typedef struct block {
        size_t size;
        bool free;
        struct block *next_block;
    } d_block;

    typedef struct memory {
        struct block *tiny;
        struct block *small;
        struct block *large;
    } d_memory;

#endif