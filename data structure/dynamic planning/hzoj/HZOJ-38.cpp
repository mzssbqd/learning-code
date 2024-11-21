#include<iostream>
#include<vector>
using namespace std;
class Bigint:public vector<int>
{
    public:
    Bigint(){
        push_back(0);
    }
    Bigint(int x)
    {
        this->push_back(x);
        process_digit();
    }
    void process_digit()
    {
        for(int i=0;i<size();i++)
        {
            if(at(i) < 10) continue;
            if(i == size() -1) push_back(0);
            at(i+1)+=at(i)/10;
            at(i)=at(i)%10; 
        }
        return;
    }
    Bigint &operator+=(const Bigint& a)
    {
        for(int i=0;i<a.size();i++)
        {
            if(i>=this->size()) push_back(a[i]);
            else at(i)+=a[i];
        }
        process_digit();
        return *this;
    }
    Bigint operator+(const Bigint& a)
    {
        Bigint ret(*this);
        ret+=a;
        return ret;
    }
};

Bigint f[105];

ostream& operator<<(ostream& out,const Bigint& a)
{
    for(int i=a.size()-1;i>=0;i--)
    {
        out<<a[i];
    }
    return out;
}

int main()
{
    int n;
    cin>>n;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    cout<<f[n]<<endl;
    return 0;
}