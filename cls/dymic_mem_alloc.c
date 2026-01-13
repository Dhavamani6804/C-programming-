#include <stdio.h>
#include <stdlib.h>

// Dynamic memory allocation
// 1. malloc() - Allocates specified number of bytes and returns a pointer to the first byte.
// 2. calloc() - Allocates memory for an array of elements, initializes them to
// 3. realloc() - Resizes previously allocated memory block.
// 4. free() - Deallocates previously allocated memory.

int main()
{
    int *DynamicVariable = (int *)malloc(5 * sizeof(int));
    printf("Address of DynamicVariable: %p\n", (void *)DynamicVariable);
    if (DynamicVariable == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        DynamicVariable[i] = i + 1;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", DynamicVariable[i]);
    }

    printf("Size of allocated memory: %zu bytes\n", sizeof(DynamicVariable));
    free(DynamicVariable);
    DynamicVariable=NULL;
    printf("Address of DynamicVariable: %p\n", (void *)DynamicVariable);

    return 0;
}