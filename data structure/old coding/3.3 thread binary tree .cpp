#include <iostream>
using namespace std;
typedef struct Node
{
    int key;
    int ltag,rtag;//1: thread  2.edge
    struct Node *lchild,*rchild;
}Node;

Node *getNewNode(int key)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->key=key;
    p->ltag=p->rtag=0;
    p->lchild = p->rchild =NULL;
    return p;
}
Node *insert(Node* root,int key)
{
    if(root==NULL) return getNewNode(key);
    if(rand()%2) root->lchild = insert(root->lchild,key);
    else root->rchild=insert(root->rchild,key);
    return root; 
}
void clear(Node* root)
{
    if(root==NULL)return;
    if(root->ltag==0)clear(root->lchild);
    if(root->rtag==0)clear(root->rchild);
    free(root);
    return;
}
void pre_order(Node* root)//前序遍历
{
    if(root==NULL) return;
    cout<<root->key<<" ";
     if(root->ltag==0)pre_order(root->lchild);
     if(root->rtag==0)pre_order(root->rchild);
    return;   
}
void in_order(Node *root)//中序遍历
{
    if(root==NULL) return;
    if(root->ltag==0)in_order(root->lchild); 
    cout<<root->key<<" ";
    if(root->rtag==0)in_order(root->rchild);
    return;   
}
Node* pre_Node=NULL,*inorder_front=NULL;
void __build_inorder_thread(Node* root)
{
    if(root==NULL) return;
    if(root->ltag==0)__build_inorder_thread(root->lchild);
    if(inorder_front==NULL) inorder_front=root;
    if(root->lchild==NULL)root->lchild=pre_Node,root->ltag=1;
    if(pre_Node && pre_Node->rchild==NULL)pre_Node->rchild=root,pre_Node->rtag=1;
    pre_Node=root;
    if(root->rtag==0)__build_inorder_thread(root->rchild);
    return;
}
void build_inorder_thread(Node* root)
{
    __build_inorder_thread(root);
    pre_Node->rchild=NULL;
    pre_Node->rtag=1;
    return;
}
//like linklist
Node *getNext(Node* root)
{
    if(root->rtag==1)return root->rchild;
    root=root->rchild;
    while(root->ltag==0 && root->lchild!=NULL) root=root->lchild;
    return root;
}
void post_order(Node *root)//后序遍历
{
    if(root==NULL) return;
    if(root->ltag==0)post_order(root->lchild);
    if(root->rtag==0)post_order(root->rchild);
    cout<<root->key<<" ";
    return;   
}
int main()
{
    srand(time(0));
    #define MAX_NUM 10
    Node *root=NULL;
    for(int i=0;i<MAX_NUM;i++)
    {
        root=insert(root,rand()%100);
    }
    pre_order(root);cout<<endl;
    in_order(root);cout<<endl;
    post_order(root);cout<<endl;
    build_inorder_thread(root);
    Node *node=inorder_front;
    while(node!=NULL) 
    {
        cout<<node->key<<" ";
        node=getNext(node);
    }
    clear(root);
    return 0;
}