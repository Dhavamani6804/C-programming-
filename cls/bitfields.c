#include <stdio.h>

struct StructBitfields
{
    unsigned char D0 : 1;
    unsigned char D1 : 1;
    unsigned char D2 : 1;
    unsigned char D3 : 1;
    unsigned char D4 : 1;
    unsigned char D5 : 1;
    unsigned char D6 : 1;
    unsigned char D7 : 1;
} StatusRegister;

int main()
{
    printf("Size of StatusRegister : %zu bytes\n", sizeof(StatusRegister));
    StatusRegister.D0 = 1;
    StatusRegister.D1 = 0;
    StatusRegister.D2 = 1;
    StatusRegister.D3 = 0;

    printf("Addres = %p\n", StatusRegister);

    return 0;
}