#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
    int n,x,m,q,size=1,temp;
    cin>>n>>m>>q;
    vector<int> arr(q);
    for(int i=0;i<q;i++)
    {
        x=n%10;
        n/=10;
        x=(x*x)%10;
        temp=n;
        while(temp>=10)
        {
            temp/=10;
            size*=10;
        }
        n=x*size*10+n;
        size=1;
        arr[i]=n;
        if(arr[i]==m)
        {
            for(int j=0;j<=i;j++) cout<<arr[j]<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}