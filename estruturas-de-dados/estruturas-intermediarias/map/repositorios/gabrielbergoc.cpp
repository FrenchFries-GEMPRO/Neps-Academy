#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
    int C, N;
    cin >> C >> N;

    unordered_map<int, int> m;

    for (int x, y, i = 0; i < C; i++) {
        cin >> x >> y;
        m[x] = y;
    }

    map<int, int> res;

    for (int x, y, i = 0; i < N; i++) {
        cin >> x >> y;
        
        int versao_comp = m[x];

        // se já não houver o programa ou a versão encontrada é mais atual que a instalada
        if (!versao_comp || y > versao_comp) {
            int versao_int = res[x];
            // instalar a maior versão dentre as encontradas na internet
            if (versao_int) y = max(y, versao_int);
            res[x] = y;
        }
    }

    for (auto [k, v] : res) {
        cout << k << " " << v << endl;
    }
}

