#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Vector
{
    int size;
    int *data;
}Vector;
Vector* initVector(int n)
{

    Vector *p=(Vector*)malloc(sizeof(Vector));
    p->size=n;
    p->data=(int*)malloc(sizeof(int)*n);
    return p;
}
void clearVector(Vector *q)
{
    if(q==NULL)return;
    free(q->data);
    free(q);
    return;
}
int vectorSeek(Vector *p,int pos)
{
    if(pos<0 || pos >=p->size)return 2;
    return p->data[pos];
}
int insertVector(Vector* p,int tail,int val)
{
    if(tail<0 || tail >=p->size)return 0;
    p->data[tail]=val;
    return 1;
}
typedef struct Queue
{
    Vector *data;
    int size,head,tail,count;
} Queue;
Queue *initQueue(int n){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->data=initVector(n);
    q->size=n;
    q->head =q->tail=q->count=0;
    return q;
}
int push(Queue *q,int val)
{
    if(q->count == q->size)return 0;
    insertVector(q->data,q->tail,val);
    q->tail+=1;
    if(q->tail==q->size) q->tail=0;
    q->count+=1;
    return 1; 
}
int front(Queue *q)
{
    return vectorSeek(q->data,q->head);
}
int empty(Queue *q)
{
    return q->count==0;
}
int pop(Queue *q)
{
    if(empty(q)) return 0;
    q->head++;
    q->count++;
    return 1;
}
void clearQueue(Queue *q)
{
    if(q==NULL)return;
    clearVector(q->data);
    free(q);
    return;
}
void coutqueue(Queue* q)
{
    printf("queue : ");
    for(int i=0;i<q->count;i++)
    {
        printf("%4d",vectorSeek(q->data,(q->head+i)%q->size));
    }
    printf("\n");
}
int main()
{
    srand(time(0));
    #define MAX_OP 10
    Queue *q=initQueue(10);
    for(int i = 0; i< MAX_OP ; i++)
    {
        int op=rand()%5 ,val=rand()%100;
        switch(op)
        {
            case 0:
            printf("front of queue : %d\n",front(q));
            pop(q);
            break;
            case 1:
            case 2:
            case 3:
            case 4:
            printf("push %d to queue\n",val);
            push(q,val);
            break;
        }
        coutqueue(q);
    }
    clearQueue(q);
    return 0;
}