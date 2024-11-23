/*************************************************************************
	> File Name: 20.p3370_stringhash.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Nov 2024 08:28:12 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int get_hash(string &s) {
    int base = 131, h = 0;
    for(int i = 0; s[i]; i++) {
        h = h * base + s[i];
    }
    return h;
}
int main() {
    int n, ans = 0;
    cin >> n;
    unordered_map<int, vector<string>> h;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        int hash_code = get_hash(s);
        if(h.find(hash_code) == h.end()) {
            ans += 1;
            h[hash_code].push_back(s);
        } else {
            int flag = 1;
            for(auto t : h[hash_code]) {
                if(t != s) continue;
                flag = 0;
                break;
            }
            if(flag) {
                ans += 1;
                h[hash_code].push_back(s);
            }
        }
    }
    cout << ans <<endl;
    return 0;
}
