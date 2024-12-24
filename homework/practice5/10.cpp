#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct stu {
    char name[50];
    int ac;
    int limit;
}s[1000];
int n, m;

bool cmp(stu s1, stu s2) {
    if(s1.ac != s2.ac) return s1.ac < s2.ac;
    if(s1.limit != s2.limit) return s1.limit > s2.limit;
    return strcmp(s1.name, s2.name);
}
int main() {
    scanf("%d%d", &n, &m);
    int cnt = 0;
    while(scanf("%s", s[cnt].name) != EOF) {
        s[cnt].ac = 0, s[cnt].limit = 0;
        char temp[30];
        for(int i = 0; i < n; i++) {
            scanf("%s", temp);
            if(temp[0] == '-') continue;
            if(temp[strlen(temp) - 1] == ')') {
                int t1, t2;
                sscanf(temp, "%d(%d)", &t1, &t2);
                s[cnt].ac += 1;
                s[cnt].limit += t1 + t2 * m;
                continue;
            }
            s[cnt].ac += !!atoi(temp);
            s[cnt].limit += atoi(temp);
            //printf("%s : %d %d\n", s[cnt].name, s[cnt].ac, s[cnt].limit);
        }
        cnt += 1;
    }
    for(int i = 0; i < cnt - 1; i++) {
        for(int j = 0; j < cnt - i - 1; j++) {
            if(cmp(s[j], s[j + 1])) {
                stu temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < cnt; i++) {
        printf("%-10s %2d %4d\n", s[i].name, s[i].ac, s[i].limit);
    }
    return 0;
}