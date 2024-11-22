#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    int scode=1,cnt=1,i=0,j=0;
    while(cnt<=n*n)
    {
        switch(scode)
        {
            case 1:
            for(;j<=n;j++) 
            {
                if(i>=0 && j>=0 && i<n && j<n && arr[i][j]==0)
                {
                    arr[i][j]=cnt++;
                }
                else 
                {
                    j--;
                    i++;
                    scode=2;
                    break;
                }
            }
            
            case 2:
            for(;i<=n;i++) 
            {
                if(i>=0 && j>=0 && i<n && j<n && arr[i][j]==0)
                {
                    arr[i][j]=cnt++;
                }
                else 
                {
                    i--;
                    j--;
                    scode=3;
                    break;
                }
            }
            
            case 3:
            for(;j+1>=0;j--) 
            {
                if(i>=0 && j>=0 && i<n && j<n && arr[i][j]==0)
                {
                    arr[i][j]=cnt++;
                }
                else 
                {
                    j++;
                    i--;
                    scode=4;
                    break;
                }
            }
            case 4:
            for(;i+1>=0;i--)
            {
                if(i>=0 && j>=0 && i<n && j<n && arr[i][j]==0)
                {
                    arr[i][j]=cnt++;
                }
                else 
                {
                    i++;
                    j++;
                    scode=1;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%3d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}