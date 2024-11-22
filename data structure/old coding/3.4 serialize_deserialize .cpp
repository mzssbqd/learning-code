#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<string.h>
#include<stack>
using namespace std;
//二叉树实现
typedef struct Node
{
    int key;
    struct Node *lchild,*rchild;
}Node;
Node* getNewNode(int key)
{
    Node* p=(Node*)malloc(sizeof(Node));
    p->key=key;
    p->lchild=p->rchild=NULL;
    return p;
}
Node* insert(Node *root,int key)
{
    if(root==NULL) return getNewNode(key);
    if(rand()%2)root->lchild=insert(root->lchild,key);
    else root->rchild=insert(root->rchild,key);
    return root;
}
void clear(Node* root)
{
    if(root==NULL)return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}
Node *getNewTree(int n)
{
    Node* root=NULL;
    for(int i=0;i<n;i++)
    {
        root=insert(root,rand()%100);
    }
    return root;
}

//广义表转换
char buff[1000];
int len;
void __serialize(Node* root)
{
    if(root==NULL)return;//忘记设置边界条件
    len+=sprintf(buff+len,"%d",root->key);
    if(root->lchild!=NULL || root->rchild!=NULL)
    {
    len+=sprintf(buff+len,"(");
    __serialize(root->lchild);
    if(root->rchild!=NULL) 
    {
        len+=sprintf(buff+len,",");
        __serialize(root->rchild);
    }
    len+=sprintf(buff+len,")");
    }
    return;
}
void serialize(Node* root)
{
    memset(buff,0,sizeof(buff));
    len=0;
    __serialize(root);
    return;
}

//deserialize
Node* deserialize()
{
    stack<Node*> s;
    int flag=0,scode=0;
    Node *p=NULL,*root=NULL;
    int inser=0;
    for(int i=0;buff[i];i++)
    {
        switch(scode)//scode 状态码,分配任务
        {
            case 0://分配任务
            {
                if(buff[i]>='0' && buff[i]<='9') scode = 1;
                else if(buff[i]=='(') scode = 2;
                else if(buff[i]==',') scode=3;
                else scode = 4;//!!!!!!!!!!!!!!else一定要写!!!!!!!!!!!!!!!!!!!!
                cout<<scode<<endl;
                i-=1;
            } break;
            case 1://包装节点
            {
                int num=0;//记录节点数字
                while(buff[i]>='0' && buff[i]<='9')//转换数字
                {
                    num=num*10+(buff[i]-48);
                    i++;
                }
                i--;//校准位子
                p=getNewNode(num);//包装节点
                if(!s.empty())//连接节点
                {
                    if(flag==0) s.top()->lchild=p;
                    if(flag==1) s.top()->rchild=p;
                }
                scode=0;//更新状态码
            }break;
            case 2:
            {
                s.push(p);
                if(inser==0)
                {
                    root=s.top();
                    inser=1;
                    cout<<inser<<endl;
                }
                flag=0;
                scode=0;
            }break;
            case 3 : 
            {
                flag=1;
                scode=0;
            }break;
            case 4:
            {
                s.pop();
                scode=0;
            }break;
        }
    }
    return root;
}
//打印输出树
#define KEY(n) (n ? n->key : -1)
void print(Node* root)
{
    printf("%d:(%d,%d)\n",KEY(root),KEY(root->lchild),KEY(root->rchild));
    return;
}
void output(Node* root)
{
    if(root==NULL)return;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return;
}
#define MAX_NODE 10
int main()
{
    srand(time(0));
    Node* root=getNewTree(MAX_NODE);//获得一棵树
    serialize(root);//转换成广义表
    output(root);cout<<endl;//输出树
    cout<<"buff[]:"<<buff<<endl;//输出广义表
    Node *new_root=deserialize();
    output(new_root);cout<<endl;
    return 0;
}