#include <iostream>
using namespace std;

typedef struct Node
{
    struct Node *next[26];
    int flag;
}Node;

Node *getNewNode()
{
    Node *p = (Node *)malloc(sizeof(Node));
    for(int i = 0 ;i < 26;i++) p->next[i] = NULL;
    p->flag = 0;
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
        int ind = s[i] - 'a';
        if(p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return;
}

int find(Node* root,const char *s)
{
    Node *p = root;
    for(int i = 0;s[i];i++)
    {
        int ind = s[i] - 'a';
        p = p ->next[ind];
        if(p == NULL) return 0;
    }
    if(p->flag == 1) return 1;
    return 0;
}
char buff[256];
void sort(Node *root ,int k)
{
    buff[k] = 0;
    if(root->flag == 1)
    {
        printf("find :%s\n" ,buff);
        return; 
    }
    for(int i = 0 ;i < 26;i++)
    {
        if(root->next[i] == NULL) continue;
        buff[k] = 'a' + i;
        sort(root->next[i] , k + 1);
    }
    return;
}
int main()
{
    int op;
    char s[100];
    Node *root = getNewNode();
    while(cin >> op)
    {
        if(op == 3) break;
        cin >> s;
        switch(op)
        {
            case 1:
            {
                insert(root,s);
            }break;
            case 2:
            {
                int flag = find(root,s);
                printf("find %s from flag : %d", s , flag);
            }break;      
        }
    }
    sort(root,0);
    return 0;
}