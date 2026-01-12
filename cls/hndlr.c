#include <stdio.h>
 
typedef void (*Handler)(void);
 
typedef struct {
    int SwitchId;
    Handler SwitchPressed;
} SwitchEvent;
 
void onSwitchOnePressed(void) {
    printf("Switch pressed!\n");
}
 
void onSwitchTwoPressed(void) {
    printf("Another switch pressed!\n");
}
 
int main() {
    //registering the handler
    SwitchEvent switchOne = {1, onSwitchOnePressed};
    SwitchEvent switchTwo = {2, onSwitchTwoPressed};
 
    // Simulate switch presses
    switchOne.SwitchPressed();
    switchTwo.SwitchPressed();
    return 0;
}
 