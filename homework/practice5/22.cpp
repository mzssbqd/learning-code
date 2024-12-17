    #include <stdio.h>
    #include <cstring>
    struct Stu {
        char name[100];
        double a, b, c, d, e, f;
        double sum;
        double SUM() {
            
            sum = a + b + c + d + e + f;
            return sum;
        }
        double ave() {
            return (a + b + c + d + e + f) * 1.0 / 6;
        }
    }s;

    int main() {
        scanf("%s", s.name);
        scanf("%lf%lf%lf%lf%lf%lf", &s.a, &s.b, &s.c, &s.d, &s.e, &s.f);
        printf("sum=%.2lf,average=%.2lf\n", s.SUM(), s.ave());
        return 0;
    }