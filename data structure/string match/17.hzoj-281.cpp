/*************************************************************************
	> File Name: 17.hzoj-281.cpp
	> Author:mzssbqd 
	> Mail: 
	> Created Time: Sat 23 Nov 2024 04:14:01 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

const int MAX_N = 3e5;
int arr[MAX_N + 5], n;

int  string_min() {
    int i = 0, j = 1, k = 0;
    while(i < n && j < n && k < n) {
        if(arr[(i + k) % n] == arr[(j + k) % n]) k += 1;
        else if(arr[(i + k) % n] > arr[(j + k) % n]) {
            i += k + 1;
            k = 0;
        }
        else {
            j += k + 1;
            k = 0;
        }
        if(i == j) j += 1;
    }
    return min(i, j);
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", arr + i);
    int ind = string_min();
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[(i + ind) % n]);
    }
    return 0;
}
