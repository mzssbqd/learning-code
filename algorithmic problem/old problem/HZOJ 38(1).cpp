#include<iostream>
using namespace std;
#define MAX_N 100
int arr[MAX_N+5]={0};
//正向递推(递归)
//1.确定递推状态:f(n)代表第n个月兔子的总对数
//2.确定递推公式:f(n)=f(n-1)+f(n-2)
//3.程序实现:
//程序效率问题:递归加记忆化,改成逆递推
//程序可行性问题:大整数
int f(int n)
{
    if(n<=2) return n;
    if(arr[n]!=0) return arr[n];
    arr[n]=f(n-1)+f(n-2);
    return arr[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}