#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int scode=1,n,z=1,k=0;
    vector<int> arr(n*n,0);
    int cnt=0;
    while(cnt<=n*n)
    {
        switch(scode)
        {
            case 1:
            if(z==1)
            {
                for(int i=0;i<n;i++)
                {
                    if(arr[i]!=0)arr[i]=cnt++;
                else
                {
                    k=i-1;
                    scode=2;
                    break;
                }
                }
            }
            else 
            {   
                for(int i=n-1;i>=0;i--)
                {
                    if(arr[i]!=0)arr[i]=cnt++;
                else
                {
                    scode=2;
                    break;
                }
            }
            }
            break;
            case 2:
            if(z==1)
            {
                for(int i=k;i<n*n;i+=n)
                {
                    
                }
            }
        }
    }
}