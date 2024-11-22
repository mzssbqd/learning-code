#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

typedef struct Node
{
    int data;//储存的数据信息
    Node *next;//指向下一个节点的指针
}Node;

//初始化操作
Node* getNewNode(int val)
{
    Node *p=(Node *)malloc(sizeof(Node));
    p->data=val;
    p->next=NULL;
    return p;
}

void clear(Node* head)
{
    if(head == NULL) return;
    for(Node* p= head,*q;p;p=q)
    {
        q= p->next;
        free(p);
    }
    return;
}

//插入操作

Node *insert(Node *head ,int pos,int val)
{
    if(pos==0)
    {
        Node *p=getNewNode(val);
        p->next=head;
        return p;
    }
    Node* p=head;
    for(int i=1;i<pos;i++)p=p->next;
    Node *node=getNewNode(val);
    node->next=p->next;
    p->next=node;
    return head;
}

//insert 2


Node *insert02(Node *head,int pos,int val)
{
    Node new_head,*p=&new_head;
    new_head.next=head;
    for(int i=0;i<pos;i++)
    {
        p=p->next;
    }
    Node* node=getNewNode(val);
    node->next=p->next;
    p->next=node;
    return new_head.next;
}


void  output_linklist(Node* head)
{
   Node* p= head;
   int len=0;
   while(p)
   {
    p=p->next;
    len++;
   }
   int num=0;
    for(int i=1;i<=len;i++)
    {
        num+=printf("%3d  ",i);
    }
    printf("\n");
    for(int i=1;i<=num;i++)
    {
        printf("-");
    }
    printf("\n");
    p=head;
    for(int i=1;i<=len;i++)
    {
        printf("%3d",p->data);
        printf("->");
        p=p->next;
    }
    printf("\n\n\ndf");

}
int main()
{   
    
    srand(time(0));
    #define MAX_OP 10
    Node* head =NULL;
    for(int i=0;i<MAX_OP;i++)
    {
        int position=rand()%(i+1),val=rand()%100;
        printf("insert %d at %d to linklist\n",val,position);
        head = insert(head,position,val);
        output_linklist(head);
    }

    return 0;
}