#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    do {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));
    return 0;
}