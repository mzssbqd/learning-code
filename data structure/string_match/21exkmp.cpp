/*************************************************************************
	> File Name: 21.2exkmp.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Nov 2024 09:41:05 PM CST
 ************************************************************************/
#include<iostream>
#include <cstring>
using namespace std;
const int MAX_N = 2e7;
char a[MAX_N + 5], b[MAX_N + 5];
long long z[MAX_N + 5];
long long ans_1 = 0, ans_2 = 0;
void get_z() {
    int l = -1, r = -1;
    int slen = strlen(b);
    z[0] = slen;
    for(int i = 1; i < slen; i++) {
        if(r >= i) z[i] = min((long long)r - i + 1, z[i - l]);
        while(z[i] + i < slen  && b[i + z[i]] == b[z[i]]) z[i] += 1;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return ;
}
int main() {
    scanf("%s%s", a, b);
    get_z();
    long long l = -1, r = -1;
    for(int i = 0, I = strlen(a),blen = strlen(b); i < I; i++) {
        long long p = 0;
        if(r >= i) p = min(z[i - l], (long long)r - i + 1);
        while(i + p < I && p < blen && b[p] == a[i + p]) p += 1;
        if(i + p - 1 > r) l = i, r = i + p - 1;
        ans_2 ^= (1 + i) * (p  + 1);
    }
    for(int i = 0, I = strlen(b); i < I; i++) {
        ans_1 ^= (i + 1) * (z[i] + 1);
    }
    printf("%lld\n%lld",ans_1, ans_2);
    return 0;
}   