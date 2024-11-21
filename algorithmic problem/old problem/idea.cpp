#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    for(int i=0,sum=0;i<a;i++)
    {
        
        for(int j=0;j<sum;j++)
        {
            printf(" ");
        }
        for(int k=0;k<b;k++)
        {
            printf("*");
        }
        printf("\n");
        sum+=c;
    }
    return 0;
}