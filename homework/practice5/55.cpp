#include <stdio.h>

struct Book {
    char name[100];
    int large;
}a[15];

int main() {
    for(int i = 0; i < 10; i++) {
        scanf("%s%d", a[i].name, &a[i].large);
    }
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9 - i; j++) {
            if(a[j].large > a[j + 1].large) {
                Book temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            } 
        }
    }
    for(int i = 0; i <= 9; i++) {
        printf("%s %d\n", a[i].name, a[i].large);
    }
    return 0;
}