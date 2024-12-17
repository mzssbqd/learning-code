#include <iostream>
using namespace std;
int main() {
    int a[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    cout << **a << endl;
    cout << a[0] << endl;
    return 0;
}