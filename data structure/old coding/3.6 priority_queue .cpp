#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<time.h>
using namespace std;
#define FATHER(i) (i/2)
#define LEFT(i) (i*2)
#define RIGHT(i) (i*2+1)
typedef struct PriorityQueue
{
    int *data,*__data;
    int size,n;
}priorityQueue;

//initialize priority queue
PriorityQueue *initPQ(int size)
{
    PriorityQueue *pq=(PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->__data=(int*)malloc(sizeof(int)*size+1);
    pq->data=pq->__data-1;
    pq->size=size;
    pq->n=0;
    return pq;
}
int empty(PriorityQueue *pq)
{
    return pq->n==0;
}
int full(PriorityQueue *pq)
{
    return pq->n==pq->size;
}

int top(PriorityQueue *pq)
{
    return pq->data[1];
}

void up_maintain(int *data,int i)
{
    if(i == 1) return;
    if(data[i] >data[FATHER(i)]) 
    {
        swap(data[i],data[FATHER(i)]);
        up_maintain(data,FATHER(i));
    }
    return;
}
void down_maintain(int *data,int i,int n)
{
    if(i>=n) return  ;
    int ind=i, l=LEFT(i) ,r=RIGHT(i);
    if(data[l] && data[l] > ind) ind = l;
    if(data[r] && data[r] > ind) ind = r;
    swap(data[ind],data[i]);
    if(ind == i) return;
    down_maintain(data,ind,n);
    return;
}
int push(PriorityQueue *p,int x)
{
    if(full(p)) return 0;
    p->n+=1;
    p->data[p->n]=x;
    up_maintain(p->data,p->n);
    return 1;
}

int pop(PriorityQueue *p)
{
    if(empty(p)) return 0;
    p->data[1]=p->data[p->n];
    p->n-=1;
    down_maintain(p->data,1,p->n);
    return 1;
}

void clearPQ(PriorityQueue *pq)
{
    if(pq==NULL) return;
    free(pq->data);
    free(pq);
    return;
}
void output(PriorityQueue* p)
{
    for(int i=1;i<=p->n;i++)
    {
        cout<<p->data[i]<<" ";
    }
    cout<<endl;
    return;
}
int main()
{
    #define MAX_OP 10
    PriorityQueue* p=initPQ(MAX_OP);
    int op;
    while(cin>>op && op!=-1)
    {
        if(op==1)
        {
            int x;
            cin>>x;
            push(p,x);
            cout<<"insert"<<x<<"to priority_queue:"<<endl;
            output(p);
            cout<<endl;
        } 
        else
        {
            pop(p);
            cout<<"pop a element:\n\n";
            output(p);
        }
    }
    return 0;
}