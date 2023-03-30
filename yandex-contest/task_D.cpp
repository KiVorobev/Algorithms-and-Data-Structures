#include <iostream>

using namespace std;

int main() {
    int a, buff = 0;
    uint16_t b, c, d;
    uint64_t k;

    cin >> a >> b >> c >> d >> k;

    for (int i = 0; i < k; i++) {
        a = a * b - c;
        if (a <= 0) {
            a = 0;
            break;
        }
        if (a > d) a = d;
        if (a == buff) break;
        buff = a;
    }
    cout << a;
    return 0;
}