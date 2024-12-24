#include <stdio.h>

struct Address  {
    char street[100];
    char city[100];
};
struct Person {
    char name[55];
    struct Address ad;
};

void print_person_address(struct Person p) {
    printf("Name: %s, Street: %s, City: %s", p.name, p.ad.street, p.ad.city);
}
int main() {
    Person p;
    scanf("%s%s%s", p.name, p.ad.street, p.ad.city);
    print_person_address(p);
    return 0;
}