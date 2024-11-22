#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void output(vector<int> &arr)
{
    int n=arr.size(),len=0;
    for(int i=0;i<n;i++)
    {
        len+=printf("%3d",i);
    }
    printf("\n");
    for(int i=1;i<len;i++)
    {
        printf("-");
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%3d",arr[i]);
    }
    return;
}
int main()
{
    int n;
    srand(time(NULL));
    cin>>n;
    vector<int> arr;
    stack<int> s;
    arr.push_back(-1);
    for(int i=0,a;i<n;i++)
    {
        a=rand()%100;
        arr.push_back(a);
    }
    arr.push_back(-1);
    output(arr);
    vector<int> l(arr.size()),r(arr.size());
    for(int i=0,I=arr.size();i<I;i++)
    {
        while(!s.empty() && arr[s.top()]>arr[i])
        {
            r[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=arr.size()-1;i>=0;i--)
    {
        while(!s.empty() && arr[s.top()]>arr[i])
        {
            l[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        printf("arr[%d](%d):l=arr[%d]=%d,r=arr[%d]=%d\n",i,arr[i],
        l[i],arr[l[i]],
        r[i],arr[r[i]]);
    }
    return 0;
}