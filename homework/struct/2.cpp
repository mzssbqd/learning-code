#include <stdio.h> 

 struct Person { 

 char name[50]; 

 int age; 

}; 

 void print_person(Person p) { 

 printf("Name: %s, Age: %d", p.name, p.age); 

} 

int main() { 

 Person p; 

 scanf("%s%d", p.name, &p.age); 

 print_person(p); 

 return 0; 

​}