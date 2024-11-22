#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string> arr;//不能带n大小,会发生缓冲区越界
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        arr.push_back(s);
    }
    sort(arr.begin(),arr.end(),[&](const string& i,const string& j)->bool
    {
        return i+j>j+i;
    });
    for(int i=0;i<n;i++) cout<<arr[i];
    cout<<endl;
    return 0;
}