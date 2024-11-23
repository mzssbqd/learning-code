#include <iostream>
#include <queue>
using namespace std;

typedef struct Node
{
    struct Node *next[26];
    int flag;
    struct Node *fail;
}Node;

Node *getNewNode()
{
    Node *p = (Node *)malloc(sizeof(Node));
    for(int i = 0 ;i < 26;i++) p->next[i] = NULL;
    p->flag = 0;
    p->fail = NULL;
    return p;
}
void clear(Node *root)
{
    if(root == NULL) return;
    for(int i = 0 ; i < 26;i++) clear(root->next[i]);
    free(root);
    return;
}

void insert(Node* root,const char *s)
{
    Node *p = root;
    for(int i = 0; s[i] ;i++)
    {
        cout << "test" <<endl;
        int ind = s[i] - 'a';
        if(p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return;
}


void build_ac(Node *root)
{
    queue<Node *> q;
    for(int i = 0 ;i < 26;i++)
    {
        if(root->next[i] == NULL) continue;
        root->next[i]->fail == root;
        q.push(root->next[i]);
    }
    while(!q.empty())
    {
        Node *cur = q.front(), *p;
        q.pop();
        for(int i = 0; i < 26; i++)
        {
            if(cur->next[i] == NULL) continue;
            p = cur ->fail;
            while(p && p->next[i] == NULL) p = p->fail;
            if(p == NULL) p = root;
            else p = p->next[i];
            cur->next[i]->fail = p;
            q.push(cur->next[i]);
        }
    }
    return ;
}

void find_ac(Node *root, const char *s)
{
    Node *p = root , *q;
    for(int i = 0; s[i]; i++)
    {
        int ind = s[i] - 'a';
        while(p && p->next[ind] == NULL) p = p->fail;
        if(p == NULL) p = root;
        else p = p->next[ind];
    }
}
int main()
{
    cout << "test" <<endl;
    int op;
    char s[100];
    Node *root = getNewNode();
    return 0;
}