#include <iostream>
#include <stack>

using namespace std;

static int get_count_of_pairs(string input) {
    return input.size() / 2;
}

int main() {
    string input;
    cin >> input;
    stack<int> traps;
    stack<int> animals;
    stack<char> buffer;
    int result[get_count_of_pairs(input)];
    int animalsCounter = 0;
    int trapsCounter = 0;

    for (int i = 0; i < input.size(); i++) {

        if (islower(input[i])) {
            animalsCounter++;
            animals.push(animalsCounter);
        } else {
            trapsCounter++;
            traps.push(trapsCounter);
        }

        if (buffer.empty() || input[i] == buffer.top() || tolower(input[i]) != tolower(buffer.top())) {
            buffer.push(input[i]);
        } else {
            result[traps.top()] = animals.top();
            animals.pop();
            traps.pop();
            buffer.pop();
        }
    }

    if (buffer.empty()) {
        cout << "Possible" << endl;
        for (int i = 1; i < get_count_of_pairs(input) + 1; i++) {
            cout << result[i] << " ";
        }
    } else {
        cout << "Impossible";
    }
    return 0;
}