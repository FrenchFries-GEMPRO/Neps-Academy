#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> list;
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        list.insert(x);
    }

    cout << list.size() << endl;
}