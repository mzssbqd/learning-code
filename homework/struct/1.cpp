#include <stdio.h>

struct Person {
    char name[50];
    double score;
};

int main() {
    Person p, g;
    int n;
    g.score = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s%lf", p.name, &p.score);
        if(p.score > g.score) g = p;
    }
    printf("Top student: %s, Score: %.1lf", g.name, g.score);
    return 0;
}