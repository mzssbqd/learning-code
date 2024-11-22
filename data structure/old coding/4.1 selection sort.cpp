#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<time.h>
#define THRESHOLD 16
#define TEST(func,arr)\
{\
    cout<<"test:"<<#func<<endl;\
    vector<int> temp(arr.begin(),arr.end());\
    long long b=clock();\
    func(temp);\
    long long e=clock();\
    if(check(temp)==true) cout<<"success!\t";\
    else cout<<"error!";\
    cout<<temp.size()<<"size time:"<<1000*(e-b)/CLOCKS_PER_SEC<<"ms"<<endl;\
}
#define SMALL_DATA 5000
#define BIG_DATA 1000000
using namespace std;
bool check(vector<int>& temp)
{
    for(int i=1;i<temp.size();i++)
    {
        if(temp[i-1]>temp[i]) return false;
    }
    return true;
}
vector<int> get_arr(int n)
{
    srand((unsigned int)time(NULL));
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(rand()%100000);
    }
    return v;
}
//选择排序
void selection_sort(vector<int> &arr)
{
    for(int i=0;i<arr.size()-1;i++)
    {
        int ind=i;
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[j]<arr[ind]) ind=j;
        }
        swap(arr[i],arr[ind]);
    }
    return;
}
//插入排序
void insert_sort(vector<int> &arr)
{
    for(int i=1;i<arr.size();i++)
    {
        int ind=i;
        while(ind>0 && arr[ind]<arr[ind-1])
        {
            swap(arr[ind],arr[ind-1]);
            ind-=1;
        }
    }
    return;
}
//插入排序优化
void better_insert_sort(vector<int> &arr)
{
    int ind1=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[ind1]>arr[i]) ind1=i;
    }
    while(ind1>0)
    {
        swap(arr[ind1],arr[ind1-1]);
        ind1-=1;
    }
    for(int i=1;i<arr.size();i++)
    {
        int ind=i;
        while(arr[ind]<arr[ind-1])
        {
            swap(arr[ind],arr[ind-1]);
            ind-=1;
        }
    }
    return;
}
//希尔增量序列
void insert_sort(vector<int>& arr,int l,int step)
{
    int ind1=l;
    for(int i=l+step;i<(int)arr.size();i+=step)
    {
        if(arr[ind1]>arr[i]) ind1=i;
    }
    while(ind1>l)
    {
        swap(arr[ind1],arr[ind1-step]);
        ind1=ind1-step;
    }
    for(int i=l+step;i<(int)arr.size();i+=step)
    {
        int ind=i;
        while(arr[ind]<arr[ind-step]) 
        {
            swap(arr[ind],arr[ind-step]);
            ind-=step;
        }
    }
    return;
}
void shell_sort(vector<int>& arr)
{
    int k = 2,n = arr.size(),step;
    do
    {
        step= (n/k ==0 ? 1 : n/k);
        for(int i=0;i<step;i++)
        {
            insert_sort(arr,i,step);//i:从i开始
        }
        k*=2;
    }while(step != 1);
}
//hibbard增量序列
void hibbard_shell_sort(vector<int>& arr)
{
    int multi=1,step;
    while(multi*2-1<=arr.size()/2) step=multi*2-1,multi+=1;
    do
    {        
        step=step/2;
        for(int i=0;i<step;i++)
        {
            insert_sort(arr,i,step);//i:从i开始
        }

    }while(step>1);
    return;
}
//冒泡排序
void bubble_sort(vector<int>& arr)
{
    for(int i=arr.size()-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
    return;
}
void better_bubble_sort(vector<int>& arr)
{
    for(int i=arr.size()-1;i>0;i--)
    {
        int cnt=0;
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]),cnt++;
        }
        if(cnt==0) return;
    }
    return;
}
//快速排序
void __quick_sort(vector<int> &arr,int l,int r)
{
    if(r-l<=1) return;
    int x=l,y=r-1,base=arr[l];
    while(x<y)
    {
        while(x<y && base<=arr[y]) --y;
        if(x<y) arr[x++]=arr[y];
        while(x<y && base>=arr[x]) ++x;
        if(x<y) arr[y--]=arr[x];
    }
    arr[x]=base;
    __quick_sort(arr,l,x);
    __quick_sort(arr,x+1,r);
}
void quick_sort(vector<int>& arr)
{
    int l=0,r=arr.size();
    __quick_sort(arr,l,r);
}

void __quick_sort_v1(vector<int> &arr,int l,int r)
{
    if(r-l<=0) return;
    int x=l,y=r,base=arr[r];
    while(x<=y)
    {
        while(arr[x] < base) x++;
        while(arr[y] > base) y--;
        if(x<=y)swap(arr[x++],arr[y--]);
    }
    //swap(arr[l],arr[x]);
    __quick_sort_v1(arr,l,y);
    __quick_sort_v1(arr,x,r);
    return;
}
void quick_sort_v1(vector<int>& arr)
{
    int l=0,r=arr.size()-1;
    __quick_sort_v1(arr,l,r);
}

inline int getMiddle(int a,int b,int c)
{
    if(a<b) swap(a,b);
    if(a<c) swap(a,c);
    if(b<c) swap(c,b);
    return b;
}
void __quick_sort_v2(vector<int> &arr,int l,int r)
{
    if(r-l<=0) return;
    int x=l,y=r,z=getMiddle(arr[l],arr[r],arr[(l+r)/2]);
    while (x <= y)
    {
        while (arr[x] < z) ++x;
        while (arr[y] > z) --y;
        if (x <= y) swap(arr[x++], arr[y--]);
    }
    //arr[x]=base;
    __quick_sort_v2(arr,l,y);
    __quick_sort_v2(arr,x,r);
}
void quick_sort_v2(vector<int>& arr)
{
    int l=0,r=arr.size()-1;
    __quick_sort_v2(arr,l,r);
}

void __quick_sort_v3(vector<int> &arr,int l,int r)
{
    while(r-l>=0)
    {
    int x=l,y=r,z=getMiddle(arr[l],arr[r],arr[(l+r)/2]);
    while (x <= y)
    {
        while (arr[x] < z) ++x;
        while (arr[y] > z) --y;
        if (x <= y) swap(arr[x++], arr[y--]);
    }
    //arr[x]=base;
    __quick_sort_v3(arr,l,y);
    l=x;
    }
    return;
}
void quick_sort_v3(vector<int>& arr)
{
    int l=0,r=arr.size()-1;
    __quick_sort_v3(arr,l,r);
}

void __quick_sort_v4(vector<int> &arr,int l,int r)
{
    if(r-l<=THRESHOLD) return;
    int x=l,y=r,z=getMiddle(arr[l],arr[r],arr[(l+r)/2]);
    while (x <= y)
    {
        while (arr[x] < z) ++x;
        while (arr[y] > z) --y;
        if (x <= y) swap(arr[x++], arr[y--]);
    }
    __quick_sort_v4(arr,l,y);
    __quick_sort_v4(arr,x,r);
    return;
}
void quick_sort_v4(vector<int>& arr)
{
    int l=0,r=arr.size()-1;
    __quick_sort_v4(arr,l,r);
    better_insert_sort(arr);
    return;
}
//归并排序
vector<int> glo_temp(BIG_DATA);
void __merge_sort(vector<int>& arr,int l,int r)
{
    if(r-l<=1) return;
    int mid=(l+r)/2;
    __merge_sort(arr,l,mid);//对左区间进行归操作
    __merge_sort(arr,mid,r);//对右区间进行归操作
    int p1=l,p2=mid,k=0;
    while(p1<mid || p2<r)
    {
        if(p1<mid && (p2>=r || arr[p1]<=arr[p2])) 
        glo_temp[k++]=arr[p1++];
        else glo_temp[k++]=arr[p2++];
    }
    for(int i=l;i<r;i++) arr[i]=glo_temp[i-l];
    return;
}
void merge_sort(vector<int>& arr)
{
    int l=0,r=arr.size();
    __merge_sort(arr,l,r);
    return;
}

//基数排序
#define K 65536
void radix_sort(vector<int>& arr)
{
    int *cnt=new int[K];
    vector<int> temp(arr.size());
    for(int i=0;i<K;i++) cnt[i]=0;
    for(int i=0;i<arr.size();i++) cnt[arr[i]%K]+=1;
    for(int i=1;i<K;i++) cnt[i]+=cnt[i-1];
    for(int i=arr.size()-1;i>=0;i--) temp[--cnt[arr[i]%K]]=arr[i];
    arr.swap(temp);
    for(int i=0;i<K;i++) cnt[i]=0;
    for(int i=0;i<arr.size();i++) cnt[arr[i]/K]+=1;
    for(int i=1;i<K;i++) cnt[i]+=cnt[i-1];
    for(int i=arr.size()-1;i>=0;i--) temp[--cnt[arr[i]/K]]=arr[i];
    arr.swap(temp);
}
void Bucket_sort(vector<int>& arr)
{
    int *cnt=new int[BIG_DATA];
    vector<int> temp(arr.size());
    for(int i=0;i<arr.size();i++) cnt[i]=0;
    for(int i=0;i<arr.size();i++) cnt[arr[i]]+=1;
    for(int i=1;i<arr.size();i++) cnt[i]+=cnt[i-1];
    for(int i=arr.size()-1;i>=0;i--) temp[--cnt[arr[i]]]=arr[i];
    arr.swap(temp);
    return;
}

void down_updata(vector<int>& arr,int i,int n)
{
    if(2*i+1 > n) return;
    int l=2*i+1,r=2*i+2,ind=i;
    if(arr[ind]<arr[l]) ind=l;
    if(r<=n && arr[ind]<arr[r]) ind=r;
    if(ind==i) return;
    swap(arr[ind],arr[i]);
    i=ind;
    down_updata(arr,i,n);
    return;
}
void heap_sort(vector<int>& arr)
{
    int n=arr.size()-1;
    for(int i=(n+1)/2;i>=0;i--) down_updata(arr,i,n);
    for(int i=n;i>=1;i--)
    {
        swap(arr[i],arr[0]);
        down_updata(arr,0,i-1);
    }
    return;
}
void sortusing(vector<int>& arr)
{
    sort(arr.begin(),arr.end(),less<int>());
    return;
}
int main()
{
    vector<int> big_arr=get_arr(BIG_DATA);
    vector<int> small_arr=get_arr(SMALL_DATA);
    TEST(selection_sort,small_arr);
    TEST(insert_sort,small_arr);
    TEST(better_insert_sort,small_arr)
    TEST(shell_sort,big_arr);
    TEST(hibbard_shell_sort,big_arr);
    TEST(bubble_sort,small_arr);
    TEST(better_bubble_sort,small_arr)
    TEST(quick_sort,big_arr);
    TEST(quick_sort_v1,big_arr);
    TEST(quick_sort_v2,big_arr);
    TEST(quick_sort_v3,big_arr);
    TEST(quick_sort_v4,big_arr);
    TEST(merge_sort,big_arr);
    TEST(radix_sort,big_arr);
    TEST(Bucket_sort,big_arr);
    TEST(heap_sort,big_arr);
    TEST(sortusing,big_arr);
    return 0;
}