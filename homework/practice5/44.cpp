#include <stdio.h>
#include <iostream>
using namespace std;
union u{
    char s;
    int k;
}a;
int main() {
    char s;
    scanf("%c", &s);
    int flag = 1;
    if((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) flag = 0;
    if(flag) {
        scanf("%d", &a.k);
        printf("%d", a.k * a.k);
    }
    else {
        scanf(" %c", &a.s);
        int k = (int)a.s;
        printf("%d", k);
    }
    return 0;   
}