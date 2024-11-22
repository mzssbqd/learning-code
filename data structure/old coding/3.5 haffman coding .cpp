#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<time.h>
#include<string.h>
#include<fstream>//1
using namespace std;
#define FATHER(i) (i/2)
#define LEFT(i) (i*2)
#define RIGHT(i) (i*2+1)
typedef struct Node
{
    char ch;
    int freq;
    Node *lchild,*rchild;
}Node;

//Heap
typedef struct Heap
{
    Node **__data, **data;
    int n,size;
}Heap;
Heap* getNewHeap(int size)
{
    Heap* h=(Heap*)malloc(sizeof(Heap));
    h->__data=(Node**)malloc(sizeof(Node*)*size);
    h->n=0;
    h->data = h->__data-1;
    h->size = size;
    return h;
}
int emptyHeap(Heap* h)
{
    return h->n==0;
}
Node *top(Heap *h)
{
    if(emptyHeap(h)) return NULL;
    return h->data[1];
}
void up_maintain(Heap* h,int n)
{
    if(n==1 && FATHER(n)<1) return;
    if(h->data[n]->freq<h->data[FATHER(n)]->freq)
    {
        swap(h->data[n],h->data[FATHER(n)]);
        n=FATHER(n);
    } else return;
    up_maintain(h,n);
    return;
}
void down_maintain(Heap* h,int i,int n)
{
    int ind=i,l=LEFT(i),r=RIGHT(i);
    if(l>n) return;
    if(h->data[ind]->freq > h->data[l]->freq) ind=l;
    if(h->data[r] && h->data[ind]->freq > h->data[r]->freq) ind=r;
    if(ind == i) return;
    swap(h->data[ind],h->data[i]);
    down_maintain(h,ind,n);
}
bool pushHeap(Heap *h,Node *node)
{
    if(h->size==h->n) return false;
    h->n+=1;
    h->data[h->n] = node;
    up_maintain(h,h->n);
    return 1;
}

int popHeap(Heap *h)
{
    if(emptyHeap(h)) return 0;
    h->data[1] = h->data[h->n];
    h->n-=1;
    down_maintain(h,1,h->n);
    return 1;
}
void clearHeap(Heap* h)
{
    if(h==NULL) return;
    free(h->__data);
    free(h);
    return;
}





Node *getNewNode(int freq,char ch)
{
    Node *p=(Node *)malloc(sizeof(Node));
    p->ch=ch;
    p->freq=freq;
    p->lchild=p->rchild=NULL;
    return p;
}
Node *new_buildHaffmantree(Node **node_arr,int n)
{
    Heap *h=getNewHeap(n);
    for(int i=0;i<n;i++) pushHeap(h,node_arr[i]);
    for(int i=1;i<n;i++)
    {
        Node *node1 =top(h);
        popHeap(h);
        Node *node2=top(h);
        popHeap(h);
        Node *node3 = getNewNode(node1->freq+node2->freq,0);
        node3->lchild = node1;
        node3->rchild = node2;
        pushHeap(h,node3);
    }
    Node *ret=top(h);
    clearHeap(h);
    return ret;
}
//haffman tree implementation
int find_min_freq(Node** node_arr,int n)
{
    int ind=0;
    for(int j=1;j<=n;j++)
    {
        if(node_arr[ind]->freq>node_arr[j]->freq) ind=j;
    }
    return ind;
}
void swap_node(Node** node_arr,int i,int j)
{
    Node *temp=node_arr[i];
    node_arr[i]=node_arr[j];
    node_arr[j]=temp;
}
Node *buildHaffmantree(Node **node_arr,int n)
{

    Node *node=NULL;
    for(int i=1;i<n;i++)
    {
        int ind1=find_min_freq(node_arr,n-i);
        swap_node(node_arr,ind1,n-i);
        int ind2=find_min_freq(node_arr,n-i-1);
        swap_node(node_arr,ind2,n-i-1);
        //设置新节点
        int new_freq=node_arr[n-i]->freq+node_arr[n-i-1]->freq;//新的子树频率相加
        node=getNewNode(new_freq,-1);
        node->lchild=node_arr[n-i-1];//freq高的放左子树,freq低的放在右子树
        node->rchild=node_arr[n-i];
        node_arr[n-i-1]=node;
    }
    return node; 
}
//haffman coding implementaion
#define MAX_CHAR_NUM 128
char *letter_code[128]={0};
void extract_haffmantree(Node *root,char buff[],int k)
{
    buff[k]=0;
    if(root->lchild==NULL && root->rchild==NULL)
    {
        letter_code[(int)root->ch]=strdup(buff);
        return;
    }
    buff[k]='0';
    extract_haffmantree(root->lchild,buff,k+1);
    buff[k]='1';
    extract_haffmantree(root->rchild,buff,k+1);
    return;
}
void clear(Node* root)
{
    if(root==NULL)return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}
void input()
{
    srand(time(0));
    fstream ofs;
    ofs.open("F:\\data structure\\input.txt",ios::out);
    for(int i=0;i<26;i++)
    {
        ofs<<(char)('a'+i)<<" "<<rand() % 10000<<endl;
    }
    ofs.close();
}
int main()
{
    input();
    int n;
    cin>>n;
    Node **node_arr=(Node**)malloc(sizeof(Node*));
    //写入数据
    char s;//s:reading letter
    int freq;//freq:reading frequency
    ifstream ifs;//2
    ifs.open("F:\\data structure\\input.txt",ios::in);//3
    for(int i=0;i<n;i++)//4
    {
        ifs>>s>>freq;//read in data
        node_arr[i]=getNewNode(freq,s);//packaging node
    }
    Node *root=buildHaffmantree(node_arr,n);
    //extract haffman coding
    char buff[1000]={0};
    extract_haffmantree(root,buff,0);
    for(int i=0;i<MAX_CHAR_NUM;i++)
    {
        if(letter_code[i]==NULL)continue;
        cout<<(char)i<<":"<<letter_code[i]<<endl;
    }
    clear(root);
    return 0;
}