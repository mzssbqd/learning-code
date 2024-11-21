#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    int s;
    cin>>n>>s;
    for(int i=0;i<s;i++)
    {
        int j=0;
        while(n[j+1] && n[j]<=n[j+1]) j++;
        while(n[j]) n[j]=n[j+1],j+=1;//erase a cnt
    }
    for(int i=0,flag=1;n[i];i++)
    {
        if(n[i]=='0' &&  flag==1) continue;
        cout<<n[i];
        flag=0;
    }
    cout<<endl;
    return 0;
}