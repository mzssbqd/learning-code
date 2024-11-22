#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<inttypes.h>
#include<time.h>
using namespace std;
typedef struct Node
{
    int key,level;//数据节点
    struct Node* next,*down,*up;
}Node;
typedef struct Skiplist
{
    Node *head,*tail;
    int max_level;
}Skiplist;
#define MAX_LEVEL 32

double randDouble()
{
    #define MAX_RAND_N 1000000
    return (rand()%MAX_RAND_N*1.0)/MAX_RAND_N;
    #undef MAX_RAND_N
}
int randlevel(Skiplist *s)
{
    int level=1;
    double p=1.0/2.0;
    while(randDouble()>p) level+=1;
    return min(s->max_level,level);
}
Node* getNewNode(int key,int n)
{
    Node *p=(Node*)malloc(sizeof(Node)*n);
    for(int i=0;i<n;i++)
    {
        p[i].key=key;
        p[i].level=i;
        p[i].next=NULL;
        p[i].down=(i==0 ? NULL : p+(i-1));
        p[i].up=(i>=n-1 ? NULL : p+(i+1));
    }
    return &p[n-1];
}
Skiplist* getNewList(int n)
{
    Skiplist* p=(Skiplist*)malloc(sizeof(Skiplist));
    p->head=getNewNode(INT32_MIN,n);
    p->tail=getNewNode(INT32_MAX,n);
    Node *s=p->head,*q=p->tail;
    while(s)
    {
        s->next=q;
        s=s->down,q=q->down;
    }
    //while(p->head->level!=0) p->head=p->head->down;
    p->max_level=n;
    return p;
}
void clearNode(Node* p)
{
    if(p==NULL) return;
    free(p);
}
void clearSkiplist(Skiplist *s)
{
    Node *p=s->head,*q;
    while(p->level!=0)p=p->down;
    while(p!=NULL)
    {
        q=p->next;
        clearNode(p);
        p=q;
    }
    free(s);
}
Node *find(Skiplist *s,int x)
{
    Node *p=s->head;
    while(p!=NULL)
    {
        if(p->next->key==x) return p->next;
        if(p->next->key<x) p=p->next;
        else p=p->down;
    }
    return p;
}
void insert(Skiplist* s,int x)
{
    int level=randlevel(s);
    while(s->head->level+1<level) s->head=s->head->up;
    Node *node=getNewNode(x,level);
    Node* p=s->head;
    while(p->level!=node->level) p=p->down;
    while(p && p->next->key<node->key) p=p->next;
    while(p)
    {
        node->next=p->next;
        p->next=node;
        p=p->down,node=node->down;
    }
    return;
}
void output(Skiplist *s)
{
    Node *p=s->head;
    while(p->level>0) p=p->down;
    p=p->next;
    Node *q=p;
    while(q->key!=INT32_MAX)
    {
        printf("%4d ",q->key);
       q=q->next;
    }
    return;
}
int main()
{
    srand(time(0));
    int x;
    Skiplist *s=getNewList(MAX_LEVEL);
    while(~scanf("%d",&x))
    {
        if(x==-1) break;
        insert(s,x);
        output(s);
    }
    while(~scanf("%d",&x))
    {
        Node* p=find(s,x);
        printf("find result:\n");
        if(p!=NULL)
        {
            printf("key=%d,level=%d\n",p->key,p->level);
        }else printf("1\n");
    }
    return 0;
}