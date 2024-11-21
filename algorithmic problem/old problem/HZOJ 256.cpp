#include<iostream>
#include<stack>
using namespace std;
#define MAX_NUM 10000
int main()
{   
    stack<int> s;
    char str[MAX_NUM+5];
    int match[MAX_NUM+5]={0};
    cin>>(str+1);
    for(int i=1;str[i];i++)
    {
        switch(str[i])
        {
            case '(' :
            case '[' :
            case '{' :
                    s.push(i);
                    break;
            case ')' :
            if(!s.empty() && str[s.top()]=='(')
            {
                match[s.top()]=i;
                s.pop();
            }
            else s.push(i);
            break;
            case ']' :
             if(!s.empty() && str[s.top()]=='[')
            {
                match[s.top()]=i;
                s.pop();
            }
            else s.push(i);
            break;
            case '}' :
             if(!s.empty() && str[s.top()]=='{')
            {
                match[s.top()]=i;
                s.pop();
            }
            else s.push(i);
            break;
        }
    }
    int temp_ans=0,ans=0,i=1;
    while(str[i])
    {
        if(match[i])
        {
            temp_ans+=(match[i]-i+1);
            i=match[i]+1;
        }
        else temp_ans=0,i+=1;
        if(temp_ans>ans) ans=temp_ans;
    }
    cout<<ans;
    return 0;
}