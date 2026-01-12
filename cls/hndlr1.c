#include <stdio.h>

typedef void (*Handler) (int);

typedef struct {
int SwitchId;
Handler SwitchPressed;
} SwitchEvent;

void onSwitchPressed(int switchId) {
printf("Switch %x pressed!\n", switchId);
}

int main() {
SwitchEvent switchOne;
switchOne.SwitchId = 0x12;
switchOne. SwitchPressed = onSwitchPressed;
switchOne.SwitchPressed(switchOne.SwitchId);
SwitchEvent switchTwo;
switchTwo.SwitchId = 0x34;
switchTwo. SwitchPressed = onSwitchPressed;
switchTwo.SwitchPressed(switchTwo.SwitchId);
return 0;
}