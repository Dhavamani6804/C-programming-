#include <stdio.h>

enum Fruits
{
    APPLE = 2,
    BANANA,
    ORANGE = 9,
    GRAPE = 'A'
};

typedef enum EFI_STATUS
{
    EFI_SUCCESS = 0,
    EFI_LOAD_ERROR = 1,
    EFI_INVALID_PARAMETER = 2,
    EFI_UNSUPPORTED = 3
} EFI_STATUS;

enum SwitchState
{
    OFF = 0,
    ON = 1
};

int main()
{
    printf("Fruits Enum Values:\n");
    printf("APPLE: %d\n", APPLE);
    printf("BANANA: %d\n", BANANA);
    printf("ORANGE: %d\n", ORANGE);
    printf("GRAPE: %d\n", GRAPE);

    char SwitchValue = ON;
    if (SwitchValue == OFF)
    {
        printf("The switch is OFF.\n");
    }
    else if (SwitchValue == ON)
    {
        printf("The switch is ON. \n");
    }
    else
    {
        printf("Invalid switch state. \n");
    }
    return 0;
}