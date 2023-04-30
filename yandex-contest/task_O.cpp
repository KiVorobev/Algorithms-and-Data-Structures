#include <iostream>
#include <vector>

using namespace std;

bool depth_first_search(vector<int> *lkshats, int *condition, int index, int type_of_condition) {
    condition[index] = type_of_condition;
    for (int lkshat: lkshats[index]) {
        if (condition[lkshat] != 0) {
            if (condition[lkshat] == type_of_condition) return false;
        } else {
            if (!depth_first_search(lkshats, condition, lkshat, type_of_condition != 2 ? 2 : 1)) return false;
        }
    }
    return true;
}

int main() {
    int n, m, first_number, second_number;
    cin >> n >> m;
    vector<int> lkshats[n];
    int condition[n];

    for (int i = 0; i < n; i++) condition[i] = 0;

    for (int i = 0; i < m; i++) {
        cin >> first_number >> second_number;
        first_number--;
        second_number--;
        lkshats[first_number].push_back(second_number);
        lkshats[second_number].push_back(first_number);
    }

    for (int i = 0; i < n; i++) {
        if (condition[i] == 0) {
            if (!depth_first_search(lkshats, condition, i, 1)) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}