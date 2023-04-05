#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

struct data {
    char letter;
    int weight;
};

bool define_heavily(struct data x1, struct data x2) {
    return x1.weight < x2.weight;
}

int main() {
    string input;
    int weight;
    cin >> input;
    vector<struct data> weights;
    map<char, int> counter;
    for (int i = 0; i < 26; i++) {
        cin >> weight;
        weights.push_back((struct data) {(char) (0x61 + i), weight});
    }
    for (int i = 0; i < input.size(); i++) {
        if (counter.find(input[i]) == counter.end()) {
            counter.emplace(input[i], 1);
        } else {
            counter[input[i]]++;
        }
    }
    sort(weights.begin(), weights.end(), define_heavily);
    for (int i = 0; i < 26; i++) {
        char letter = weights[i].letter;
        int swapCounter = 0;
        if (counter[letter] >= 2) {
            for (int i = 0; i < input.size() && swapCounter < 2; i++) {
                if (input[i] == letter) {
                    if (swapCounter == 0) {
                        input = letter + input.substr(0, i) + input.substr(i + 1);
                        swapCounter++;
                    } else {
                        input = input.substr(0, i) + input.substr(i + 1) + letter;
                        swapCounter++;
                    }
                }
            }
        }
    }
    cout << input;
    return 0;
}