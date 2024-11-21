#include<iostream>
#include<queue>
#include<stack>
#include<time.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *lchild,*rchild;
}Node;
Node *getNewNode(int data)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=data;
    p->lchild = p->rchild =NULL;
    return p;
}
Node *insert(Node* root,int data)
{
    if(root == NULL) return getNewNode(data);
    if(rand()%2) root->lchild = insert(root->lchild,data);
    else root->rchild=insert(root->rchild,data);
    return root;
}
void clear(Node *root)
{
    if(root==NULL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}
void bfs(Node* root)
{
    if(root==NULL)return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        if(q.front()->lchild!=NULL) 
        {
            q.push(q.front()->lchild);
            cout<<q.front()->data<<"的左子树"<<q.front()->lchild->data;
        }
       if(q.front()->rchild!=NULL) 
        {
            q.push(q.front()->rchild);
            cout<<q.front()->data<<"的右子树"<<q.front()->rchild->data;
        }
        cout<<endl;
        q.pop();
    }
}
int tot=0;
void dfs(Node* root)
{
    if(root==NULL)return;
    tot+=1;
    int start=tot;
    if(root->lchild) dfs(root->lchild);
    if(root->rchild) dfs(root->rchild);
    tot+=1;
    int end=tot;
    cout<<root->data<<":["<<start<<","<<end<<"]"<<endl;
}
int main()
{
    srand(time(0));
    Node* root=NULL;
    for(int i=0;i<10;i++)
    {
        root=insert(root,rand()%100);//要用root链接 错误点1
    }
    bfs(root);
    dfs(root);
    return 0;
}