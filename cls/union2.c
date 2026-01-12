#include <stdio.h>

union Accumulator
{
    unsigned short int AX;
    struct
    {
        unsigned char AL;
        unsigned char AH;
    };
};

int main()
{
    union Accumulator MyAccumulator;
    MyAccumulator.AX = 0x1234;
    printf("AH = 0x%02X, AL = 0x%02X\n", MyAccumulator.AH, MyAccumulator.AL);
    MyAccumulator.AX = 0x56;
    printf("AH = 0x%02X, AL = 0x%02X\n", MyAccumulator.AH, MyAccumulator.AL);

    return 0;
}

