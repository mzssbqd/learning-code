#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000], b[1000], c[1000];
    while (scanf_s("%s", a, sizeof(a)) != EOF && scanf_s("%s", b, sizeof(b)) != EOF)
    {
        int m = strlen(b), n = strlen(a);
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (b[j] == a[i])
                {
                    break;
                }
                else count++;
            }
            if (count == m)
            {
                c[k] = a[i];
                k++;
            }
        }
        for (int g = 0; g < k; g++)
        {
            printf("%c", c[g]);
        }
        printf("\n");
    }
    return 0;
}