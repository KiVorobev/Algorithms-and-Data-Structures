#include <iostream>

using namespace std;

int main() {
    int n, max = 0, x1 = -1, x2 = -1, counter = 2;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n > 2) {
        for (int i = 2; i < n; i++) {
            if (a[i] != a[i - 2] || a[i] != a[i - 1]) {
                if (counter == 0) {
                    counter = 3;
                } else {
                    counter++;
                }
            } else {
                if (counter > max) {
                    max = counter;
                    x2 = i;
                    x1 = i + 1 - counter;
                }
                counter = 0;
            }
            if (i + 1 == n) {
                if (counter > max) {
                    max = counter;
                    x2 = i + 1;
                    x1 = i + 2 - counter;
                }
            }
        }
        cout << x1 << " " << x2;
    } else {
        if (n == 2) {
            cout << 1 << " " << 2;
        }
        if (n == 1) {
            cout << 1 << " " << 1;
        }
    }
    return 0;
}