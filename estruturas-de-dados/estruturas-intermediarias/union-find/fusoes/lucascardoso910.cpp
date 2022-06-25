#include <iostream>

using namespace std;

#define MAX 100100

int pai[MAX];

int find(int x) {
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    pai[x] = pai[y];
}

int main() {
    int bancos, ops;
    cin >> bancos >> ops;

    for (int i = 1; i < bancos + 1; i++) {
        pai[i] = i;
    }

    for (int i = 0; i < ops; i++) {
        char op;
        int b1, b2;

        cin >> op >> b1 >> b2;

        if (op == 'F') {
            join(b1, b2);
        } else {
            if (find(b1) == find(b2)) {
                cout << "S" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }
}