#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d > b) {
        cout << a + (d-b)*c;
    }
    if (d <= b) {
        cout << a;
    }
    return 0;
}