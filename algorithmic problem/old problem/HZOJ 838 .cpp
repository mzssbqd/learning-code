/*************************************************************************
    > File Name: solve.cpp
    > Author:
    > Mail:
    > Created Time:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int min_num(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    return a;
}

int func(queue<int> que1, queue<int> que2, queue<int> que3) {
    //TODO
    int ans = 0x3f3f3f3f;//ans储存最小值,所以此处给他一个极大值
    while(!que1.empty() && !que2.empty() && !que3.empty())
    {
        int a=que1.front(),b=que2.front(),c=que3.front();
        int temp_ans=abs(a-b)+abs(a-c)+abs(b-c);//<cstdlib>:abs():取绝对值
        if(temp_ans<ans) ans=temp_ans;
        int min=min_num(a,b,c);
        if(min==a) que1.pop();
        if(min==b) que2.pop();
        if(min==c) que3.pop();
    }
    return ans;
}

int main() {
    int m, n, k, x;
    queue<int> que1, que2, que3;
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++) {
        cin >> x;
        que1.push(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        que2.push(x);
    }
    for (int i = 0; i < k; i++) {
        cin >> x;
        que3.push(x);
    }
    cout << func(que1, que2, que3) << endl;
    return 0;
}