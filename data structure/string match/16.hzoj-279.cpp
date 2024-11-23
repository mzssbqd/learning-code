/*************************************************************************
	> File Name: 16.hzoj-279.cpp
	> Author:mzssbqd 
	> Mail: 
	> Created Time: Fri 22 Nov 2024 10:06:07 PM CST
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
#define MAX_N 1000000
char s1[MAX_N + 5],s2[MAX_N + 5];
int string_min(const char *s) {
    int slen = strlen(s), i = 0, j = 1, k = 0;
    while(i < slen && j < slen && k < slen) {
        int ind_i = (i + k) % slen, ind_j = (j + k) % slen;
        if(s[ind_i] == s[ind_j]) k += 1;
        else if(s[ind_i] < s[ind_j]) {
            j += k + 1;
            k = 0;
        }
        else {
            i += k + 1;
            k = 0;
        }
        if(i == j) j += 1;
    }
    return min(i, j);
}
int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    int ind_1 = string_min(s1);
    int ind_2 = string_min(s2);
    int flag = 1;
    for(int i = 0, I =strlen(s1);i < I; i++) {
        if(s1[(ind_1 + i) % I] == s2[(ind_2 + i) % I]) continue;
        flag = 0;
        break;
    }
    if(flag) {
        printf("Yes\n");
       
        for(int i = 0, I =strlen(s1), flag;i < I; i++) {
            cout << s1[(ind_1 + i) % I];
        }
        cout << endl;
    }
    else {
        cout << "No" <<endl;
    }
    return 0;
}
