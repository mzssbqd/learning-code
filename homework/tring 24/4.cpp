#include <iostream>
int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int ind1 = -0x3f3f3f3f, ind2 = -0x3f3f3f3f;
        for(int i = 0, a; i < n; i++) {
            scanf("%d", &a);
            if(ind2 >= a) continue;
            if(a >= ind1) {
                ind2 = ind1, ind1 = a;
            } else ind2 = a;
        }
        printf("%d %d\n", ind1, ind2);
    }
    return 0;
}