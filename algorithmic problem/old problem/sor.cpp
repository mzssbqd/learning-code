#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<>> s;
    int size,num,cnt=0;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>num;
        s.push(num);
    }
    while(s.size()!=1)
    {
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        int c;
        cnt+=c=a+b;
        s.push(c);
    }
    cout<<cnt<<endl;
    return 0;
} 