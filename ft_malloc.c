#include "ft_malloc.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <string.h>

// mmap maps memory in the virtual adress space of the calling process ?
// need to check rlimit further more 

/* Quelle est la différence entre mapper une région mémoire et allouer de la mémoire ?
Quel est exactement le rôle de l'adresse retournée par mmap ?
Quel rapport existe-t-il entre cette adresse et la taille demandée ?
Et qu'est-ce qui peut provoquer une segfault lorsqu'on accède à de la mémoire virtuelle ?*/

struct memory phonebook;

void *fetch_tiny() {
    void *starter = mmap(NULL,TINY, PROT_READ | PROT_WRITE, MAP_ANONYMOUS, -1, 0);
    if (starter == MAP_FAILED) {
        perror("mmap");
        return NULL;
    }
    return starter;
}
enum warning verify_tiny(d_block *tiny) { // mais si j'ai plus d'un bucket tiny ? 
    enum warning level;
    if (!tiny)
        return (level = NOEXIST);
    d_block *nav = tiny;
    while (nav->next_block) {
        if (free)
            return (level = OK);
        nav = nav->next_block;
    }
    return (level = FULL);
}

block *find_last_block(d_block *block) {
    d_block *nav = block;
    while (nav->next_block) {
        nav = nav->next_block;
    }
    return nav;
}
void *ft_malloc(size_t size)
{
    enum warning level;
    switch(size) {
        case (size <= 16):
            level = verify_tiny(phonebook.tiny);
            if (level == NOEXIST){
                phonebok.tiny = fetch_tiny();
            }
            else if (level == FULL) {
                write (2, "ft_malloc: Zone is exhausted !\n", 32);
                return NULL;
            }
            block new_block = {16, false, NULL};
            if () // find a way to check if there is a new block and increment it by n size;
            (find_last_block(phonebook.tiny))->next_block =  // how do i put my structure here then ? 

    }
}
//void free(void *ptr);
//void *realloc(void *ptr, size_t size);

int main (int argc, char **argv)
{
    char *base_adress;
    base_adress = ft_malloc(sizeof(char) * 7);
    char *test_adress;
    test_adress = malloc(sizeof(char) * 7);
    strcpy(test_adress, "Hello\n\0");
    block test;
    printf("block is %ld\n", sizeof(test));
    printf("Small is %ld\n", SMALL);
    printf("Large is %ld\n", LARGE);
    printf("My real malloc string is : %s", test_adress);
    strcpy(base_adress, "Hello\n\0");
    printf("My first char is : %s", base_adress);
}