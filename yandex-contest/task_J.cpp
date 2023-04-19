#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    list<int> front_queue;
    list<int> back_queue;
    char sign;
    int number;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sign;
        if (sign == '+') {
            cin >> number;
            back_queue.push_back(number);
        }
        else if (sign == '*') {
            cin >> number;
            front_queue.push_back(number);
        }
        else if (sign == '-') {
            cout << front_queue.front() << endl;
            front_queue.pop_front();
        }
        if (front_queue.size() < back_queue.size()) {
            front_queue.push_back(back_queue.front());
            back_queue.pop_front();
        } else if (front_queue.size() > back_queue.size() + 1) {
            back_queue.push_front(front_queue.back());
            front_queue.pop_back();
        }
    }
    return 0;
}