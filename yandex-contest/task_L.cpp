#include <iostream>
#include <list>

using namespace std;

struct data {
    int index, value;
};

int main() {
    int n, k, number;
    list<struct data> window;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> number;
        if (!window.empty() && i - window.front().index == k)
            window.pop_front(); // Убираем элемент, который "вышел из окна"
        while (!window.empty() && window.back().value > number)
            window.pop_back(); // Убираем элементы из "окна", которые больше введенного
        window.push_back((struct data) {i, number});
        if (i >= k - 1) cout << window.front().value << " ";
    }
    return 0;
}