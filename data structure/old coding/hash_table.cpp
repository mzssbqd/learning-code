#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<string.h>
using namespace std;
typedef struct Node{
    char* s;
    struct Node* next;
}Node;
typedef struct Hashtable{
    Node *data;
    int cnt,size;
}Hashtable;
Node *getNewNode(const char *s)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->s=strdup(s);//1.字符串赋值的时候最好拷贝后再赋值,不然可能出现修改了原来字符串的问题
}
int main()
{
    return 0;
}