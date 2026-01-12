#include <stdio.h>

int main() {
    int num, original, divisor = 1000, digit;
    printf("Enter a number between 1 and 9999: ");
    scanf("%d", &num);

    if (num < 1 || num > 9999) {
        printf("Number out of range.\n");
        return 0;
    }

    original = num;
    divisor = 1000;
    while (divisor > 0) {
        digit = num / divisor;
        if (digit > 0 || divisor == 1) {
            switch (digit) {
                case 1: printf("One "); break;
                case 2: printf("Two "); break;
                case 3: printf("Three "); break;
                case 4: printf("Four "); break;
                case 5: printf("Five "); break;
                case 6: printf("Six "); break;
                case 7: printf("Seven "); break;
                case 8: printf("Eight "); break;
                case 9: printf("Nine "); break;
                case 0: printf("Zero "); break;
            }
        }
        num %= divisor;
        divisor /= 10;
    }
    return 0;
}