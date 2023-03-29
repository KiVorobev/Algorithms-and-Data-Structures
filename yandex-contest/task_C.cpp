#include <iostream>
#include <map>
#include <stack>
#include <list>

using namespace std;

int main() {
    map<string, stack<int>> store;
    stack<list<string>> changes;
    changes.push(list<string>());
    string input;
    string variable;
    string inputValue;
    int index;
    while (cin >> input) {
        if (input == "{") {
            changes.push(list<string>());
        } else if (input == "}") {
            for (string name: changes.top()) {
                store[name].pop();
            }
            changes.pop();
        } else {
            index = input.find("=");
            variable = input.substr(0, index);
            inputValue = input.substr(index + 1);
            if (isdigit(inputValue[0]) || inputValue[0] == '-') {
                store[variable].push(stoi(inputValue));
            } else {
                if (store.find(inputValue) == store.end() || store[inputValue].empty()) {
                    store[inputValue].push(0);
                }
                store[variable].push(store[inputValue].top());
                cout << store[variable].top() << endl;
            }
            changes.top().push_front(variable);
        }
    }
    return 0;
}