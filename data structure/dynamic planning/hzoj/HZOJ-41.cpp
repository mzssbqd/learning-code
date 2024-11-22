#include<iostream>
#include<vector>
using namespace std;
#define MAX_N 1000
#define MAX_K 10
class Bigint:public vector<int>
{
    public:
    Bigint(){
        push_back(0);
    }
    Bigint(int x)
    {
        push_back(x);
        process_digit();
    }
    Bigint& operator+=(const Bigint& a)
    {
        for(int i=0;i<a.size();i++)
        {
            if(this->size()<=i) push_back(a[i]);
            else at(i)+=a[i];
        }
        process_digit();
        return *this;
    }
    Bigint& operator*(const int a)
    {
        for(int i=0,I=size();i<I;i++)
        {
            at(i)*=a;
        }
        process_digit();
        return *this;
    }
    void process_digit()
    {
        for(int i=0;i<size();i++)
        {
            if(at(i)<100000) continue;
            if(i==size()-1) push_back(0);
            at(i+1)+=at(i)/100000;
            at(i)%=100000;
        }
        //while(size()!=0 && at(size()-1)==0) this->pop_back();
    }
};
ostream& operator<<(ostream& out,const Bigint& a)
{
    out<<a[a.size()-1];
    for(int i=int(a.size())-2;i>=0;i--)
    {
        for(int j=10000;j>0;j/=10)
        {
            out<<a[i]%(j*10)/j;
        }
    }
    return out;
}
Bigint f[MAX_N+5];
int main()
{
    int n,k;
    cin>>n>>k;
    f[1]=k;
    f[2]=k*(k-1);
    f[3]=k*(k-1)*(k-2);
    for(int i=4;i<=n;i++)
    {
        f[i]=f[i-1]*(k-2);
        f[i]+=f[i-2]*(k-1);
    }
    cout<<f[n]<<endl;
    return 0;
}