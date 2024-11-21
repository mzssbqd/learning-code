//Quick-find算法中merge操作的时间复杂度是O(n),原因是要更改每一个节点的颜色
//但其实我们不需要让知道颜色,只需要知道两个颜色一样即可
//所以我们可以利用树形结构,将两个需要联通node所在树合并为一个树,则代表这个树上node的颜色都相同
//这就是Quick-union算法

#include<iostream>
using namespace std;

#define MAX_N 10000
int fa[MAX_N+5];

void init(int n)
{
    for(int i=0;i<n;i++) fa[i]=i;
    return;
}

int find(int n)
{
    int ind=n;
    while(fa[ind]!=ind)
    {
        ind=fa[ind];
    }
    return ind;
}
//只要ind!=val,都有父节点
int merge(int a,int b)
{
    int aa=find(a),bb=find(b);
    if(aa==bb) return 0;
    fa[aa]=bb;
    return 1;
}
void output(int n)
{
    int ret=0;
    for(int i=0; i<n ; i++ )
    {
        ret+=printf("%3d",i);
    }
    printf("\n");
    for(int i=0;i<ret;i++) printf("-");
    printf("\n");
    for(int i=0; i<n ; i++ )
    {
        printf("%3d",fa[i]);
    }
}
int main()
{
    int n,a,b;
    cin>>n;
    init(n);
    while(cin>>a>>b)
    {
        printf("merge %d with %d : %d\n",a,b,merge(a,b));
        output(n);
    };
    return 0;
}

/*
    
    1   2   3   4   5


    5   6   6   9   7

*/