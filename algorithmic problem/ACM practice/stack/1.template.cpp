#include <iostream>
using namespace std;
const int N = 3e6 + 10;
int stk[N + 5], tt;
int arr[N + 5], st[N + 5];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        while(tt && arr[stk[tt]] < arr[i]) st[stk[tt--]] = i;
        stk[++tt] = i;
    }
    for(int i = 1;i <= n; i++) {
        printf("%d ", st[i]);
    }
    return 0;
}