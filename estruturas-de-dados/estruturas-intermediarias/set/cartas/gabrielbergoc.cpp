#include <iostream>
#include <set>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    set<int> a;
    for (int x, i = 0; i < A; i++) {
        cin >> x;
        a.insert(x);
    }

    set<int> b;
    for (int x, i = 0; i < B; i++) {
        cin >> x;
        b.insert(x);
    }

    int diffA = 0;
    for (auto x : a) {
        if (b.find(x) == b.end()) diffA++;
    }

    int diffB = 0;
    for (auto x : b) {
        if (a.find(x) == a.end()) diffB++;
    }

    cout << min(diffA, diffB) << endl;

}