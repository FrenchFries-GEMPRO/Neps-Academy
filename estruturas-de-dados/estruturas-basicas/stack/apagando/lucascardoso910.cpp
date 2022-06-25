#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int written, deleted;
    stack<int> to_delete;
    string number;

    while (true) {
        vector<pair<int, int>> numbers;
        vector<int> to_be_deleted;

        cin >> written >> deleted;
        if (written == 0 && deleted == 0) break;

        cin >> number;

        for (int i = 0; i < number.length(); i++) {
            numbers.push_back(make_pair(number[i] - '0', i));
        }
        for (int i = numbers.size() - 1; numbers[i].first == 0 && i >= 0; i--) {
            numbers[i].first = 10;
        }

        sort(numbers.begin(), numbers.end());

        for (int i = 0; i < deleted; i++) {
            to_be_deleted.push_back(numbers[i].second);
        }
        sort(to_be_deleted.begin(), to_be_deleted.end());

        for (int i = 0; i < deleted; i++) {
            to_delete.push(to_be_deleted[i]);
        }

        while (!to_delete.empty()) {
            number.erase(number.begin() + to_delete.top());
            to_delete.pop();
        }

        cout << number << endl;
    }
}