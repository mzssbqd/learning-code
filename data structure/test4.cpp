#include <stdio.h>
#include <string.h>
char c[100][100];
char temp[100];
int main() {
    int n;
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; i++) scanf("%s",c[i]);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n - 1 - i ; j++)
        {
            if(strcmp(c[j] , c[j + 1]) > 0)
            {
                strcpy(temp , c[j]);
                strcpy(c[j] , c[j + 1]);
                strcpy(c[j + 1] , temp);
            }
        }
    }
    for(int i = 0 ;i < n; i++)
    {
        printf("%s" , c[i]);
        if(i != n - 1) printf("\n");
    }
    return 0;
}