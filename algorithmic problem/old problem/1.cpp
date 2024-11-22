#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;//输入一个数字
    int front=0,end=0;//front:记录最高位次,end:记录最低位次
    int f=1;//f:记录最低位次的等级
    int temp=x;
    while(temp>=10)//获得x最高位次的等级
    {
        temp=temp/10;
        f=f*10;
    }
    while(x!=0)
    {
    front=x/f;//获得最高位次
    end=x%10;//获得最低位次
    if(front!=end) return false;
    x=x%f/10;//先通过取余把最高位去掉,再除以10把最低位去掉.如12321,变成232
    //此时最高位的等级发生了变化,因此要改变最高位的等级
    f=f/100;
    }   
    return true;

}