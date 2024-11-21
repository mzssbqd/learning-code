#include<iostream>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int top=-1,flag=1;
        int len=s.size();
        char *stack=new char[len];
        for(int i=0;i<len;i++)
        {
            if(s[i]=='[' || s[i]=='{' || s[i]=='(')
            {
                top+=1;
                stack[top]=s[i];
            }
            else 
            {
                if(top==-1)return false;
                switch(s[i])
                {
                    case ')':{if(stack[top]=='(')top--;else flag==0;}break;
                    case '}':{if(stack[top]=='{')top--;else flag==0;}break;
                    case ']':{if(stack[top]=='[')top--;else flag==0;}break;
                }
            }
            if(flag==0) break;
        }
        if(top!=-1 || flag==0) return false;
        return true;
    }
};
int main()
{
    Solution a;
    a.isValid("(])");
}