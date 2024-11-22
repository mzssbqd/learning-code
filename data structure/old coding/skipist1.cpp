#include<iostream>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<inttypes.h>
#include<time.h>
using namespace std;
#define MAX_LEVEL 32
class Node
{
    public:
    Node(){}
    Node(int key,int level)
    {
        Node* node=new Node[level];
        for(int i=1;i<level-1;i++)
        {
            node[i].key=key;
            node[i].level=i;
            node[i].down= node+(i-1);
            node[i].up  = node+(i+1);
        }
        forward=&node[level-1];
        end=&node[0];
    }
    ~Node()
    {
        if(end!=NULL)
        {
            delete[] end;
            end=NULL;
        }
    }
    int key,level;
    Node *forward,*end;
    Node *next,*down,*up;
};

class List
{
    public:
    List()
    {
        Node head1(INT32_MIN,MAX_LEVEL),tail1(INT32_MAX,MAX_LEVEL);
        head=head1.forward,tail=tail1.forward;
        Node *p1=head,*p2=tail;
        while(p1!=NULL)
        {
            p1->next=p2;
            p1=p1->down,p2=p2->down;
        }
    }
    double rand_double()
    {
        srand(time(0));
        #define MAX_N 1000000
        return ((rand()%MAX_N)*1.0/MAX_N);
    }
    int randlevel()
    {
        int level=1;
        double p=1.0/2.0;
        while(rand_double()<p) level+=1;
        return min(level,MAX_LEVEL);
    }
    void insert(int val)
    {
        Node *node=new Node(val,randlevel());
        Node *p=head;
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
    Node* head,*tail;
};
int main()
{
    return 0;
}