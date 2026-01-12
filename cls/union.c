#include <stdio.h>

union Data
{
    int IntVar;
    char CharVar;
};

int main()
{
    union Data data;
    printf("Size of union Data: %zu bytes\n", sizeof(data));
    data.IntVar = 65;
        printf("Data as CharVar: %c\n", data.CharVar);

    printf("Data as IntVar: %d\n", data.IntVar);
    data.CharVar = 'B';
    printf("Data as CharVar: %c\n", data.CharVar);
        printf("Data as IntVar: %d\n", data.IntVar);

    return 0;
}
