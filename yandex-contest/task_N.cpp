#include <iostream>
#include <vector>

using namespace std;

struct data {
    vector<int> banks;
    int condition = 0;
};

void depth_first_search(struct data banks_data[], int index, int *counter) {
    banks_data[index].condition = 1;
    for (int bank: banks_data[index].banks) {
        if (banks_data[bank].condition == 0) depth_first_search(banks_data, bank, counter);
        else if (banks_data[bank].condition == 1) (*counter)++;
    }
    banks_data[index].condition = 2;
}

int main() {
    int n, number, counter = 0;
    cin >> n;
    struct data banks_data[n];
    for (int i = 0; i < n; i++) {
        cin >> number;
        number--;
        banks_data[number].banks.push_back(i);
    }
    for (int i = 0; i < n; i++) depth_first_search(banks_data, i, &counter);
    cout << counter;
    return 0;
}