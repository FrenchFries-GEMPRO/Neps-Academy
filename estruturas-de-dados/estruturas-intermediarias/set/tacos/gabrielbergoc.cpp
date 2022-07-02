#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int c;
    cin >> c;

    int count = 0;
    unordered_set<int> stock;
    for (int x, i = 0; i < c; i++) {
        cin >> x;
        if (stock.find(x) == stock.end()) {
            count += 2;
            stock.insert(x);
        } else {
            stock.erase(x);
        }
    }

    cout << count << endl;
}