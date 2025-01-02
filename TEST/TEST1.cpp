#include<stdio.h>
struct Person
{
    int age;
    char name[100];
}t;
void print_person(struct Person p)
{
    printf("Name: %s, Age :%d", p.name, p.age);
}
int main()
{
    scanf_s("%s%d", t.name, 100, &t.age);
    printf("%d", t.age);
    print_person(t);
    return 0;
}