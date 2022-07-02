#include <iostream>

#define MAXN (int) 1E5 + 1

using namespace std;

int pai[MAXN];
int peso[MAXN];

int find(int x) {
    if (pai[x] == x) return x;

    pai[x] = find(pai[x]);
    return pai[x];
}

void join(int x, int y) {

    x = find(x);
    y = find(y);

    if (x == y) return;

    pai[x] = y;
    return ;

    // otimização desnecessária:
    if (peso[x] > peso[y]) {
        pai[y] = x;
    } else {
        pai[x] = y;
        if (peso[x] == peso[y]) peso[y]++;
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) pai[i] = i;

    for (int i = 0; i < K; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;

        if (c == 'F') join(a, b);
        else {
            if (find(a) == find(b)) cout << 'S' << endl;
            else cout << 'N' << endl;
        }
    }
}