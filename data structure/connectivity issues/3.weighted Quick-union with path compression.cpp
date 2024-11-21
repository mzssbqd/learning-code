/*
1.如果树退化为链表,那么find的效率会退化为o(n)
optimization: 
(1).按秩优化:
    1)height:低的挂在高的上面
    2)size:把少的挂在多的上面
(2).路径压缩优化:
    在find操作的时候,把son node挂到 root上
    均摊时间复杂度o(1)
*/
#include<iostream>
using namespace std;

#define MAX_N 10000
int fa[MAX_N+5];
int num[MAX_N+5];
void init(int n)
{
    for(int i=0;i<n;i++) 
    {   fa[i]=i;
        num[i]=i;
    }
    return;
}

int find(int n)
{
    return fa[n]=(fa[n] == n ? n : find(fa[n]));
}
int merge(int a,int b)
{
    int aa=find(a),bb=find(b);
    if(aa==bb) return 0;
    //按秩优化
    if(num[aa] < num[bb])
    {
        fa[bb]=aa;
        num[bb]+=num[aa];
    }
    else 
    {
        fa[aa]=bb;
        num[aa]+=num[bb];
    }
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