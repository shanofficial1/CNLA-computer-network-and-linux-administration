#include <stdio.h>

int main() {
    int num = 10;
    char str[10];

    sprintf(str, "%d", num);

    printf("%s", str,typeof(str));
    return 0;
}
