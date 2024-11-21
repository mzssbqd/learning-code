#include<iostream>
#include<time.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(){}
    Node(int n):data(n),next(NULL){}
    Node(int n,Node *p):data(n),next(p){}
};
class ListNode
{
    public:
    Node head;
    Node *new_head=&head,*tail;
    ListNode()
    {
        tail=new_head;
        new_head->next=NULL;
    }
    //insert node
    
    int insert(int val)
    {
        Node *p=new Node(val);
        tail->next=p;
        tail=p;
        return 1;
    }
    
    int listpop()
    {
        Node *temp=new_head->next;
        new_head->next=new_head->next->next;
        delete temp;
        return 1;
    }
    //erase ListNode
    void clear()
    {
        while(new_head->next!=NULL)
        {
            Node* temp=new_head;
            new_head=new_head->next;
            delete temp;
        }
    }
};

class Queue
{
    public:
    int count;
    ListNode *list;
    Queue()
    {
        list=new ListNode;
        count=0;
    }
    //judge if queue is empty
    int empty()
    {
        return this==NULL;
    }
    int front()
    {
        if(empty())return 0;
        return list->head.data;
    }

    int push(int val)
    {
        list->insert(val);
        return 1;
    }
    
    int pop()
    {
        list->listpop();
        return 1;
    }
    void print()
    {
        Node *p=list->new_head;
        while(p->next!=NULL)
        {
            p=p->next;
            cout<<p->data<<" ";
        }
        cout<<endl;
    }
    ~Queue()
    {
        if(list!=NULL)
        {
            list->clear();
            list=NULL;
        }
    }
};



int main()
{
    Queue qu;
    srand(time(0));
    #define MAX_ON 10
    for(int i=0;i<MAX_ON;i++)
    {
        int a=rand()%101;
        qu.push(a);
        qu.print();
    }
    for(int i=0;i<MAX_ON;i++)
    {
        qu.pop();
        qu.print();
    }
    return 0;
}