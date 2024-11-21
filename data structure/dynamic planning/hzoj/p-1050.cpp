#include<iostream>
using namespace std;
int main()
{
    int n,k,base=1,x,y;
    cin>>n>>k;
    for(int i=0;i<k;i++,base*=10);
    x=n%base;//23
    y=x;//23
    int cnt=1;
    while(x*y%base!=x)//23 *23 29 
    {
        cout<<"y == "<<y<< ", cnt=" <<cnt<<endl;
        y=y*x%base;//
        cnt+=1;
    } 
    return 0;   
}