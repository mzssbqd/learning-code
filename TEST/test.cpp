#include<stdio.h>
#include <stdlib.h>

int main()
{
    int k, m, n;
    scanf_s("%d %d %d", &k, &m, &n);
    int a[k];
    for (int i = 0; i < k; i++)
    {
        scanf_s("%d", &a[i]);
    }
    for (int j = 0; j < k - 1; j++)
    {
        for (int h = j + 1; h < k; h++)
        {
            if (a[j] > a[h])
            {
                int t = a[j];
                a[j] = a[h];
                a[h] = t;

            }
        }
    }
    
    printf("%d %d", a[k - m], a[n - 1]);
    return 0;
}