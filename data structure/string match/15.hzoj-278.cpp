/*************************************************************************
	> File Name: 15.hzoj-278.cpp
	> Author:mzssbqd 
	> Mail: 
	> Created Time: Fri 22 Nov 2024 09:03:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

const int MAX_L = 1e6;
char s[MAX_L + 5];
int next_l[MAX_L + 5];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s", s);
    int j = -1;
    next_l[0] = -1;
    for(int i = 1; s[i]; i++) {
        while(j != -1 && s[i] != s[j + 1]) j = next_l[j];
        if(s[i] == s[j + 1]) j += 1;
        next_l[i] = j;
        if(j != -1 && (i + 1) % (i - j) == 0) {
            printf("%d %d\n", i + 1, (i + 1) / (i - j));
            cout << i + 1 << i - j << endl;
        }
    }
    for(int i = 0;i < n; i++) cout << next_l[i] <<" ";
    return 0;
}
