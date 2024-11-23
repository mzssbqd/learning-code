#include <iostream>
using namespace std;
#define MAX_N 1000000


typedef struct DANode
{
    int base,check;
}DANode;
int tire_root = 1;
DANode tire[MAX_N + 5];

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


int get_base(Node *root)
{
    int base = 2;
    do
    {
        int flag = 1;
        for(int i = 0 ;i < 26;i++)
        {
            if(root->next[i] == NULL) continue;
            if(tire[base + i].check == 0) continue;
            flag = 0;
            break;
        }
        if(flag == 1) break;
        base += 1;
    }while(1);
    return base;
}
void convert_to_doubleArrayTire(Node *root, int ind)
{
    tire[ind].base = get_base(root);
    for(int i = 0; i < 26 ;i++)
    {
        if(root->next[i] == NULL) continue;
        tire[tire[ind].base + i].check = (root->next[i]->flag == 1 ? -ind : ind); 
    }
    for(int i = 0; i < 26 ;i++)
    {
        if(root->next[i] == NULL) continue;
        convert_to_doubleArrayTire(root->next[i] , tire[ind].base + i);
    }
    return;
}

int find(const char *s)
{
    int p = tire_root;
    for(int i = 0 ; s[i]; i++)
    {
        int ind = tire[p].base + s[i] -'a';
        if(abs(tire[ind].check) != p) return 0;
        p = ind;
    }
    return tire[p].check < 0;
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
int main()
{
    int n;
    cin >> n;
    char s[100];
    Node *root = getNewNode();
    for(int i =0 ;i < n ;i++)
    {
        cin >> s;
        insert(root, s);
    }
    convert_to_doubleArrayTire(root, tire_root);
    while(cin >> s)
    {
        printf("find %s from doubleArraryTire : %d",s,find(s));
    }
    return 0;
}