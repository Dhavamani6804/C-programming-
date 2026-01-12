#include <stdio.h>

union Data
{
    unsigned char IntVar;
    unsigned char CharVar;
};

int main()
{
    union Data data;
    printf("Size of union Data: %zu bytes\n", sizeof(data));
    data.IntVar = 0xFD;
    printf("Data as IntVar: %x\n", data.IntVar);
    data.CharVar = 0x10;
    printf("Data as CharVar: %x\n", data.CharVar);
    printf("Data as IntVar after modifying CharVar: %x\n", data.IntVar);
    return 0;
}
