#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool define_our_greater_element(string &x1, string &x2) {
    return x1 + x2 < x2 + x1;
}

int main() {
    string input;
    vector<string> store;
    while (cin >> input) {
        store.push_back(input);
    }
    sort(store.begin(), store.end(), define_our_greater_element);
    for (int i = store.size(); i > 0; i--) {
        cout << store[i - 1];
    }
    return 0;
}