#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Stack
{
    char *data;
    int size,top;
}Stack;

Stack* initStack(int n)
{
    Stack* s=(Stack*)malloc(sizeof(Stack));
    s->data=(char *)malloc(sizeof(char)*n);
    s->size = n ;
    s->top =-1;
    return s;
}
int empty(Stack* s)
{
    return s->top==-1;
}
char Top(Stack *s)
{
    if(empty(s)) return 0;
    return s->data[s->top];
}
int push(Stack* s,char val)
{
    if(s->top+1==s->size) return -1;
    s->top+=1;
    s->data[s->top]=val;
    return 1;
}
void pop(Stack *s)
{
    if(empty(s))return;
    s->top-=1;
    return;
}
void clearStack(Stack *s)
{
    if(s==NULL)return;
    free(s->data);
    free(s);
}
void print(Stack* s)
{
    printf("Stack: ");
    for(int i=s->top;i>=0;i--)
    {
        printf("%4d",s->data[i]);
    }
    printf("\n\n");
}
void solve(char str[])
{
    int flag=1;
    Stack* s=initStack(100);
    for(int i=0;str[i];i++)
    {
        if(str[i]=='('|| str[i]=='{'||str[i]=='{')
        {
            push(s,str[i]);
        }
        else 
        {
            switch(str[i])
            {
                case ')':if(Top(s)=='(') pop(s);
                else flag=0;break;
                case ']':if(Top(s)=='[') pop(s);
                else  flag=0;
                break;
                case '}':if(Top(s)=='{') pop(s);
                else flag=0;
                break;
            }
            while(flag==0)printf("error");
        }
        if(s->top!=-1)printf("error"); 
        return;
    }

}
int main()
{
    char str[100];
    while(~scanf("%s",str))
    {
        solve(str);
    }
    return 0;
}