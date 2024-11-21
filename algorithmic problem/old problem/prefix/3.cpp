#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> id(n+1),ind(n+1);
    id[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>id[i];
        id[i]=id[i]%7;
    }
    return 0;
}