
#include <stdio.h>
{
    int x;
    char arr[4];
    int y;
};
int main()
{
    union test t;
    t.x = 0;
    t.arr[1] ='A';
    printf("%s", t.arr);
    return 0;
}