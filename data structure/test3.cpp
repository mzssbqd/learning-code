#include <stdio.h>
#include <string.h>

int main()

{

    char c[100];
    scanf("%s", c);

    strupr(c);
    for (int i = 0,I = strlen(c); i < I; i++)
    {

        if (c[i] <= 'Z' && c[i] >= 'A')
        {
            printf("%c", c[i]);
        }
    }
    return 0;

}