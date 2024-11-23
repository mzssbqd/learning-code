#include <stdio.h>

int main() {
    int a, b, temp;
    scanf("%d %d", &a, &b);
    int temp_a = a, temp_b = b;
    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
        
    } 
    int d = a;
    int x = temp_a * temp_b / d;
    printf("%d %d", d, x);
    return 0;
}