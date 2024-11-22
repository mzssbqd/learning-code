#include <iostream>
using namespace std;

#define MAX_N 1000
int f[MAX_N + 5][MAX_N + 5];
int main()
{
    int r;
    cin >> r;
    for(int i = 1 ; i <= r;i++)
    {
        for(int j = 1; j <= i ;j++)
        {
            cin >> f[i][j];
        }
    }
    for(int i = r; i>= 1;i--)
    {
        for(int j = 1; j <=i;j++)
        {
            f[i][j] += max(f[i + 1][j] , f[i + 1][j + 1]);
        }
    }
    cout << f[1][1] <<endl;
    return 0;
}