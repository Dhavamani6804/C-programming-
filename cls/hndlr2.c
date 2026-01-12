#include <stdio.h>
 
typedef void (*Handler)(void);
 
typedef struct {
    Handler SwitchOn;
    Handler SwitchOff;
} SwitchEvent;
 
void SwitchOnHandler() {
    printf("Switch is ON\n");
}
 
void SwitchOffHandler() {
    printf("Switch is OFF\n");
}
 
 
int main() {
    SwitchEvent switchOne;
    switchOne.SwitchOn = SwitchOnHandler;
    switchOne.SwitchOff = SwitchOffHandler;
    switchOne.SwitchOn();
    switchOne.SwitchOff();
    return 0;
}
 