#include<iostream>
using namespace std;
int main()
{
    int arr[10];
    for(int& x:arr) cin>>x;
    int high,cnt=0;
    cin>>high;
    high+=30;
    for(int& x:arr)
    {
        if(x<=high) cnt+=1;
    }
    cout<<cnt<<endl;
    return 0;
}