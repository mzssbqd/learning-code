#include <stdio.h>
#include <cstring>
#include <stdlib.h>
struct stu {
    char name[20];
    int sum, score;
}student[1000];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int i = 0;
    while(scanf("%s", student[i].name) != EOF) {
        for(int j = 0; j < n; j++) {
            char s[100];
            scanf("%s", s);
            int pos1, pos2;
            pos1 = pos2 = 0;
            for(int k = 0; s[k]; i++) {
                if(s[k] == '(') pos1 = k;
                if(s[k] == ')') pos2 = k;
            }
            if(pos1 == pos2) {
                int sc = atoi(s);
                if(sc > 0) student[i].sum += 1;
            }
            else {
                int limit, sc;
                char *p1 = &s[pos1], *p2 = &s[pos2];
                sc = strncpy(s, p1, p2);
            }
        }
    }
    return 0;
}