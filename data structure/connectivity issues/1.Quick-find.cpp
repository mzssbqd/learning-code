#include<iostream>
using namespace std;

//染色思想:
//if两个点联通-->变为一个颜色

//作用:
//1.查询两个点是不是一个集合
//2.连接两个点所在的集合

//联通操作快,但合并操作慢
#define MAX_N 10000//moment of pot
int color[MAX_N+5];

void init(int n)//initize color of node
{
    for(int i=0;i<=n;i++) color[i]=i;
}

int find(int a)//return color of node
{
    return color[a];
}

int merge(int a,int b,int n)//连接
{
    int aa=find(a),bb=find(b);
    if(aa==bb) return 0;
    for(int i=0;i<=n;i++)
    {
        if(find(i)==aa) color[i]=bb;
    }
    return 1;
}
void output(int n)
{
    int ret=0;
    for(int i=0; i<=n ; i++ )
    {
        ret+=printf("%3d",i);
    }
    printf("\n");
    for(int i=0;i<ret;i++) printf("-");
    printf("\n");
    for(int i=0; i<=n ; i++ )
    {
        printf("%3d",color[i]);
    }
}
int main()
{
    int n,a,b;
    cin>>n;
    init(n);
    while(cin>>a>>b)
    {
        printf("merge %d with %d : %d\n",a,b,merge(a,b,n));
        output(n);
    };
    return 0;
}