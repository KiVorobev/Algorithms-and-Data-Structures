#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k, price, sum = 0;
    cin >> n >> k;
    multiset<int, greater<int>> storage;
    for (int i = 0; i < n; i++) {
        cin >> price;
        storage.insert(price);
    }
    int index = 1;
    for (auto element: storage) {
        if (index % k != 0) sum += element;
        index++;
    }
    cout << sum;
    return 0;
}