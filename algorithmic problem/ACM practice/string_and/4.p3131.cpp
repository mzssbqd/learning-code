    #include <iostream>
    #include <algorithm>
    #include <cstring>
    using namespace std;
    const int N = 5e4 + 10;
    long long S[N];
    int main() {
        int n;
        cin >> n;
        for(int i = 1, a; i <= n; i++) {
            scanf("%d", &a);
            S[i] = S[i - 1] + a;
        }
        int ans = 0;
        for(int i = 0; i <= 6; i++) {
            int k = n, t = 0;
            for(int j = 0; j <= n; j++) {
                if(S[j] % 7 != i) continue;
                k = j;
                break;
            }
            for(int j = n; j >= 0; j--) {
                if(S[j] % 7 != i) continue;
                t = j;
                break;
            }
            ans = max(ans, t - k);
        }
        printf("%d", ans);
        return 0;
    }