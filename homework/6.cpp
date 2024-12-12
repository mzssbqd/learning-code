#include <stdio.h>
#include <iostream>
using namespace std;

void merge_sorted_arrays(int arr1[], int len1, int arr2[], int len2, int result[]) {
    int p1, p2, k;
    p1 = p2 = k = 0;
    while(p1 < len1 || p2 < len2) {
        if(p1 < len1 && (p2 >= len2 || arr1[p1] < arr2[p2])) result[k++] = arr1[p1++];
        else result[k++] = arr2[p2++];
    }
    printf("result:");
    for(int i = 0; i < k; i++) printf(" %d", result[i]);
    return ;
}
int main() {
    int arr1[55], arr2[55], result[110], len1 = 0, len2 = 0;
    scanf("arr1:");
    int a;
    while(~scanf("%d", &a)) 
    {
        arr1[len1++] = a;
        char c = getchar();
        if(c != '\n') continue;
        else break;
    }
    scanf("arr2:");
    while(~scanf("%d", &a)) {
        arr2[len2++] = a;
        char c = getchar();
        if(c != '\n') continue;
        else break;
    }
    merge_sorted_arrays(arr1, len1, arr2, len2, result);
    return 0;
}
