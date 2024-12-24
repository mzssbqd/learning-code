#include <iostream>
using namespace std;
const int N = 10000;
int a[N], b[N], c[N];

void matrix_multiply(int *A, int *B, int *C, int m, int n, int p) {
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= p; j++) {
            for(int k = 1; k <= n; k++) {
                C[i * p + j] += A[i * n + k] * B[k * p + j];
            }
        }
    }
}
int main() {
    int m, n, p;
    cin >> m >> n >> p;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i * n + j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= p; j++) {
            cin >> b[i * p + j];
        }
    }

    matrix_multiply(a, b, c, m, n, p);
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= p; j++) {
            cout << c[i * p + j] << " ";
        }
        cout << endl;
    }
    return 0;
}