#include <iostream>
#include <list>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
    int n, k, p, car, counter = 0;
    cin >> n >> k >> p;
    map<int, int> floor;
    unordered_map<int, int> cars_on_floor;
    list<int> cars;
    unordered_map<int, list<int>> distances;
    for (int i = 0; i < p; i++) {
        cin >> car;
        if (distances.find(car) != distances.end()) distances.find(car)->second.push_back(i);
        else distances.emplace(car, (list<int>) {i});
        cars.push_back(car);
    }
    for (int i = 0; i < p; i++) {
        car = cars.front();
        if (cars_on_floor.find(car) == cars_on_floor.end()) {
            if (counter >= k) {
                cars_on_floor.erase(cars_on_floor.find((--floor.end())->second));
                floor.erase(--floor.end());
            }
            counter++;
        } else floor.erase(floor.find(i));
        cars.pop_front();
        distances.find(car)->second.pop_front();
        if (!distances.find(car)->second.empty()) {
            floor.emplace(distances.find(car)->second.front(), car);
        }
        else {
            floor.emplace(500001 + i, car);
        }
        cars_on_floor.emplace(car, car);
    }
    cout << counter;
    return 0;
}