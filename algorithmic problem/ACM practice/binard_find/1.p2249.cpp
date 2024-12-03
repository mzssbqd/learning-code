    #include <iostream>
    using namespace std;
    const int N = 1e6 + 5;
    int a[N];
    int n, m;

    int binary_find(int x) {
        int l, r, mid;
        l = 0, r = n - 1;
        while(l < r) {
            mid = (r + l) / 2;
            if(a[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return r;
    }
    int main() {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        while(m--) {
            int k;
            scanf("%d", &k);
            int pos = binary_find(k);
            if(a[pos] == k) printf("%d ", pos + 1);
            else printf("-1 ");
        }
        return 0;
    }