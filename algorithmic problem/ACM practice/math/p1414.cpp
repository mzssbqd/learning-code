#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int c[N];
int main() {
    int n, max_n = 0;
    cin >> n;
    for(int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        max_n = max(a, max_n);
        for(int j = 1; j <= a / j; j++) {
            if(a % j == 0) {
                c[j] += 1;
                if(j != a / j) c[a / j] += 1;
            }
        }
    }
    int p = max_n;
    for(int i = 1; i <= n; i++) {
        while(c[p] < i) p--;
        printf("%d\n", p);
    }
    return 0;
}