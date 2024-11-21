#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> Y(n),X(n);
    for(int i=0;i<n;i++) cin>>X[i]>>Y[i];
    sort(X.begin(),X.end());
    for(int i=0;i<n;i++) X[i]-=i;
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    int x,y,costx=0,costy=0;
    x=X[n/2],y=Y[n/2];
    for(int i=0;i<n;i++) costx+=abs(X[i]-x),costy+=abs(Y[i]-y);
    cout<<costx+costy<<endl;
}