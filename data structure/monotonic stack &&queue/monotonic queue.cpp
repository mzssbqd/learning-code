#include<iostream>
#include<time.h>
#include<queue>
#include<vector>
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
    int n,k;
    srand(time(NULL));
    cin>>n>>k;
    vector<int> arr;
    deque<int> q;
    for(int i=0,a;i<n;i++)
    {
        a=rand()%100;
        arr.push_back(a);
    }
    output(arr);
    for(int i=0;i<n;i++)
    {
        while(!q.empty() && arr[q.back()] > arr[i]) q.pop_back();
        q.push_back(i);//index
        if( i-q.front() >= k) q.pop_front();
        printf("[%d,%d] = %d\n",max(i-k+1,0),i,arr[q.front()]); 
    }
    return 0;
}