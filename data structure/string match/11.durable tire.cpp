#include <iostream>
using namespace std;

#define MAX_N 10000 // 最多要插入多少字符串
#define BASE 26
int rt[MAX_N + 5] = {0}; //第i棵树root的下标
int ch[MAX_N * 30][BASE] = {0}; // 最多有MAX_N * 30 个点,每个点有26条边
int val[MAX_N *30] = {0};
int ch_cnt = 0; //使用了多少个节点

void insert(int o, int lst, const char *s)
{
    for(int i = 0; s[i]; i++)
    {
        int ind = s[i] - 'a';
        ch[o][ind] = ++ch_cnt;//1.在o节点对应边上申请一个节点
        for(int j = 0; j < BASE; j++)//2.继承前一个节点的边
        {
            //if(j == ind) continue;
            if(ch[o][j] != 0) continue; // 如果是o节点下面ind这条边,则不需要连
            ch[o][j] = ch[lst][j];
        }
        o = ch[o][ind], lst = ch[lst][ind]; // o 和 lst节点都向ind上走
        val[o] = val[lst]; // 3.继承前一个节点的val值
    }
    val[o] += 1;//成功插入以后把当前节点标记为独立单词
    return;
}

int find_once(int a,const char *s)
{
    int p = rt[a];
    for(int i = 0; s[i]; i++)
    {
        p = ch[p][s[i] - 'a'];
    }
    return val[p];
}
int query(int a, int b, const char *s)
{
    int x1 = find_once(b, s);
    int x2 = find_once(a - 1, s);
    return x1 - x2;
}
int main()
{
    int n;
    char s[100];
    scanf("%d",&n);
    for(int i = 1 ;i <= n;i++)
    {
        scanf("%s",s);
        rt[i] = ++ch_cnt;
        insert(rt[i] , rt[i - 1], s);
    }
    int a, b;
    while(~scanf("%d%d%s", &a, &b, s))
    {
        printf("from %d to %d, find %s : %d\n"
        ,a, b, s, query(a, b, s)
        );
    }
    return 0;
}