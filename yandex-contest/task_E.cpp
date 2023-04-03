#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int coordinates[n];
    for (int i = 0; i < n; i++) {
        cin >> coordinates[i];
    }
    int right = coordinates[n - 1] - coordinates[0];
    int left = 1;
    while (left < right) {
        int counter = 1; // Так как одна корова стоит в первом стойле
        int middle = (left + right) / 2;
        int lastCord = coordinates[0];
        for (int i = 1; i < n; i++) {
            if (coordinates[i] - lastCord > middle) {
                lastCord = coordinates[i];
                counter++;
            }
        }
        if (counter >= k) left = middle + 1;
        else right = middle;
    }
    cout << left;
    return 0;
}