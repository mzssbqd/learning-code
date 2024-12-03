#include <stdio.h>
int arr[15];
void swap(int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return ;
}
int main() {
    for(int i = 0; i < 10; i++) scanf("%d", &arr[i]);
    int p = 0;
    for(int i = 0; i < 10; i++) {
        int m = p;
        for(int j = p; j < 10; j++) {
            if(arr[j] < arr[m]) m = j;
        }
        swap(m, p);
        p += 1;
    }
    for(int i = 0; i < 10; i++) {
        printf("%d", arr[i]);
        if(i != 9) printf(" ");
    }
    return 0;
}