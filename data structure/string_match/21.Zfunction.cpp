/*************************************************************************
	> File Name: 21.kmp++_p5410.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Nov 2024 09:03:48 PM CST
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

string s;
int z[20000];
int main() {
    cin >> s;
    int l, r;
    l = r = -1;
    z[0] = s.size();mZ
        if(r > i) z[i] = min(z[i - l], r - l + 1);
        while(z[i] < n && s[i + z[i]] == s[z[i]]) z[i] += 1;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return 0;
}
