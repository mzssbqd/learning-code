#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
bool isLegal(int arr[],int n)
{
    stack<int> s;
    int x=1;
    for(int i=0;i<n;i++)
    {
        if(s.empty() || s.top()<arr[i])
        {
            while(x<=arr[i]) s.push(x),x+=1;
        }
        if(s.empty() || s.top()!=arr[i]) return false;
        s.pop();
    }
    return true;
}
int main()
{
    int n,arr[25],num=20;
    cin>>n;
    for(int i=0;i<n;i++) arr[i]=i+1;
    do
    {
        if(isLegal(arr,n))
        {
            for(int i=0;i<n;i++)
            {
                cout<<arr[i];
            }
            cout<<endl;
            num--;
        }
    }while(next_permutation(arr,arr+n) && num);
    return 0;
}