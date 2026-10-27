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
void *ft_malloc(size_t size)
{
    void *base_adress;
    base_adress = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS, -1, 0); 
    if(base_adress == MAP_FAILED) {
        perror("mmap");
        return NULL;
    }
    return base_adress;
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
    printf("My real malloc string is : %s", test_adress);
    strcpy(base_adress, "Hello\n\0");
    printf("My first char is : %s", base_adress);
}