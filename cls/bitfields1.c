#include <stdio.h>

typedef union
{
    struct
    {
        unsigned char PS : 3;
    };
    struct
    {
        unsigned char PS0 : 1;
        unsigned char PS1 : 1;
        unsigned char PS2 : 1;
        unsigned char PSA : 1;
        unsigned char T0SE : 1;
        unsigned char T0CS : 1;
        unsigned char INTEDG : 1;
        unsigned char RBPU : 1;
    };
} OptionRegister;

int main()
{
    printf("Size of OptionRegister: %zu bytes\n", sizeof(OptionRegister));
    OptionRegister MyReg;
    MyReg.PS = 5; // Set PS field
    printf("PS value: %u\n", MyReg.PS);
    MyReg.PS0 = 0; // Set PS0 bit
    printf("PS Value : %u\n", MyReg.PS);

    return 0;
}
