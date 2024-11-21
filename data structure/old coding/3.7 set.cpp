#include<iostream>
#include<time.h>
#include<set>
using namespace std;
void test01()
{
    cout<<"set replace heap"<<endl;
    typedef pair<int,int> PII;
    set<PII> s;
    int tot=0;
    srand(time(0));
    for(int i=0;i<10;i++)
    {
        s.insert(PII(rand()%20,tot++));
    }
    int* i=new int(10);
    int *a =i;
    delete i;
    cout<<*a<<endl;
}
int main()
{
    cout<<"set base usage"<<endl;
    typedef pair<int,int> PII;
    set<PII> s;
    s.insert(PII(200,1));
    s.insert(PII(100,2));
    s.insert(PII(333,3));
    for(auto x : s) cout<<x.first<<endl;
    test01();
}