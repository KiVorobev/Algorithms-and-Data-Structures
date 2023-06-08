#include <iostream>
using namespace std;

void depth_first_search(int *distances, int index, int *passed_cities, int n, int middle, int *counter, bool transposed) {
    passed_cities[index] += 1;
    for(int i = 0; i < n; i++){
        int row = transposed ? (i * n + index) : (index * n + i);
        if (i != index && passed_cities[i] == transposed && distances[row] <= middle)
            depth_first_search(distances, i, passed_cities, n, middle, counter, transposed);
    }
    (*counter)++;
}

int main() {
    int n, counter;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    int distances[n][n];
    int left = INT32_MAX;
    int right = 0;
    int passed_cities[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distances[i][j];
            if (i == j) continue;
            if (distances[i][j] < left) left = distances[i][j];
            if (distances[i][j] > right) right = distances[i][j];
        }
    }
    while (left < right) {
        counter = 0;
        int middle = (left + right) / 2;
        for (int i = 0; i < n; i++) passed_cities[i] = 0;
        depth_first_search(&distances[0][0], 0, passed_cities, n, middle, &counter, false);
        depth_first_search(&distances[0][0], 0, passed_cities, n, middle, &counter, true);
        if (counter == 2 * n) right = middle;
        else left = middle + 1;
    }
    cout << left << endl;
    return 0;
}