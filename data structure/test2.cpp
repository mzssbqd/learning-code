#include <stdio.h>
#define MAX_N 100
int a[MAX_N + 5][MAX_N + 5];
int b[MAX_N + 5][MAX_N + 5];
int c[MAX_N + 5][MAX_N + 5];
int main()
{
    int m , n , p;
    scanf("%d %d %d",&m , &n , &p);
    for(int i = 1 ; i <= m ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= p ; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for(int i = 1 ;i <= m; i++)
    {
        for(int j = 1 ;j <= p;j++)
        {
            for(int k = 1 ;k <= n;k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }   
        }
    }
    for(int i = 1 ;i <= m; i++)
    {
        for(int j = 1 ;j <= p;j++)
        {
            printf("%d",c[i][j]);
            if(j != n) printf(" ");
        }
        if(i != m) printf("\n");
    }
    return 0;
}