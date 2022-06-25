#include <iostream>

using namespace std;

#define MAX 100100

int pai[MAX], pontos[MAX];

int find(int x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    pontos[x] += pontos[y];
    pai[y] = x;
}

int main() {
    int jogs, acs;
    cin >> jogs >> acs;

    while (jogs != 0 && acs != 0) {
        int wins = 0;
        
        for (int i = 1; i < jogs + 1; i++) {        
            pai[i] = i;
            cin >> pontos[i];
        }

        for (int i = 0; i < acs; i++) {
            int acao, g1, g2;
            cin >> acao >> g1 >> g2;

            if (acao == 1) {
                join(g1, g2);
            } else {
                int guilda_rafael = find(1);
                g1 = find(g1);
                g2 = find(g2);

                if (guilda_rafael == g1) {
                    if (pontos[g1] > pontos[g2]) {
                        wins++;
                    }
                } else if (guilda_rafael == g2) {
                    if (pontos[g2] > pontos[g1]) {
                        wins++;
                    }
                }
            }
        }

        cout << wins << endl;
        cin >> jogs >> acs;
    }

}