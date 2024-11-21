#include <stdio.h>
double f[3];
int main(){
    int n;
    double ans = 2;
    scanf("%d", &n);
    int ind,rind, tind;
    f[0] = 1;
    f[1] = 2;
    for(int i = 2; i <= n; i++)
    {
        ind = i % 3 ,rind = (i - 1) % 3, tind = (i - 2) % 3;
        f[ind] = f[rind] + f[tind];
        ans += f[ind] / f[rind];
    }
    printf("%.2lf", ans);
	return 0;
}