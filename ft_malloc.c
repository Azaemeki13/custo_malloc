#include "ft_malloc.h"
#include "./libft/libft.h"
#include <stdio.h>


void *ft_malloc(size_t size)
{
    sptr base_adress;
    &base_adress = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS, -1, 0);

}
//void free(void *ptr);
//void *realloc(void *ptr, size_t size);

int main (int argc, char **argv)
{
    sptr base_adress;
    base_adress = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS, -1, 0);
    printf("My base adress is : %p", &base_adress);
}