/*
内存对齐：编译器保证每个成员的储存地址是其内存的整数倍
对齐字节一般为最大字节的字节数
*/
#include <stdio.h>
#include <stddef.h>

// 定义一个结构体
struct MyStruct {
    int a;
    double b;
    char c;
};

int main() {
    // 计算成员a的偏移量
    size_t offset_a = offsetof(struct MyStruct, a);
    // 计算成员b的偏移量
    size_t offset_b = offsetof(struct MyStruct, b);
    // 计算成员c的偏移量
    size_t offset_c = offsetof(struct MyStruct, c);

    printf("Offset of member a: %zu bytes\n", offset_a);
    printf("Offset of member b: %zu bytes\n", offset_b);
    printf("Offset of member c: %zu bytes\n", offset_c);

    return 0;
}