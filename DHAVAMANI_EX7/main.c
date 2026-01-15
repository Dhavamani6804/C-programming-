#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

// Bit manipulation functions
uint8_t SetBit(uint8_t num, uint8_t bit_position)
{
    return num | (1 << bit_position);
}

uint8_t ResetBit(uint8_t num, uint8_t bit_position)
{
    return num & ~(1 << bit_position);
}

uint8_t ReadBit(uint8_t num, uint8_t bit_position)
{
    return (num >> bit_position) & 1;
}

uint8_t ToggleBit(uint8_t num, uint8_t bit_position)
{
    return num ^ (1 << bit_position);
}

// String manipulation functions
void ReverseString(char str[])
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

void IntToString(int num, char str[])
{
    int i = 0;
    int is_negative = 0;

    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }

    if (num == 0)
    {
        str[i++] = '0';
    }
    else
    {
        while (num > 0)
        {
            str[i++] = (num % 10) + '0';
            num /= 10;
        }
    }

    if (is_negative)
    {
        str[i++] = '-';
    }

    str[i] = '\0';

    ReverseString(str);
}

// Function to display binary representation
void PrintBinary(uint8_t num)
{
    printf("Binary: ");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", ReadBit(num, i));
    }
    printf("\n");
}

int main()
{
    printf("\nBit Manipulation Functions\n");

    uint8_t num = 0b10101010; // 170 in decimal
    printf("Original number: %u\n", num);
    PrintBinary(num);

    uint8_t set_result = SetBit(num, 0);
    printf("\nAfter setting bit 0: %u\n", set_result);
    PrintBinary(set_result);

    uint8_t reset_result = ResetBit(num, 7);
    printf("\nAfter resetting bit 7: %u\n", reset_result);
    PrintBinary(reset_result);

    printf("\nReading bits from original number:\n");
    for (int i = 0; i < 8; i++)
    {
        printf("Bit %d: %u\n", i, ReadBit(num, i));
    }

    uint8_t toggle_result = ToggleBit(num, 3);
    printf("\nAfter toggling bit 3: %u\n", toggle_result);
    PrintBinary(toggle_result);

    printf("\nString Manipulation Functions\n");
    printf("\nReversing the string\n");

    char str1[] = "Hello World";
    printf("\nOriginal string: %s\n", str1);
    ReverseString(str1);
    printf("Reversed string: %s\n", str1);

    ReverseString(str1);
    printf("Reversed back: %s\n", str1);

    printf("\nInteger to String Conversion\n");

    int numbers[] = {123, -456, 0, 7890};
    char str_buffer[20];

    for (int i = 0; i < 4; i++)
    {
        IntToString(numbers[i], str_buffer);
        printf("\nInteger: %d\n", numbers[i]);
        printf("String: %s\n", str_buffer);

        ReverseString(str_buffer);
        printf("Reversed: %s\n", str_buffer);
    }
    return 0;
}