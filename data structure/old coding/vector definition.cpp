#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
void test01()
{
    //容器的必要设置
    vector<int>::iterator it;//1
    vector<int>::value_type type;//2
    cout<<sizeof(type)<<endl;
    //3
    vector<int> n;//3
    vector<int>(10);
    vector<int> a(n);
    vector<int> b=n;
    vector<int> c;
    c=n;
    //4
    (&a)->~vector();
    cout<<a.size()<<endl;
    a.swap(b);
    //5
    a==b;
    a!=b;   
}
void test02()
{
    //序列的必要设置
    vector<int> a(5,4);//(size,val)
    vector<int>(5,4);//anonymous object
    vector<int> b(a.begin(),a.end()-1);
    vector c(5,0);
    //a.insert(a.begin(),c.begin());
    a.insert(a.begin(),4);
    a.insert(a.begin(),5,4);
    for(auto i:a) cout<<i<<" ";
    cout<<endl;
    for(auto i:b) cout<<i<<" ";
}
int main()
{
    
    //test01();
    test02();
    return 0;
}
