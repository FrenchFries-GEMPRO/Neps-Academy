#include <iostream>
#include <set>

using namespace std;

int main() {
    int consultas;
    int tacos = 0;
    set<int> estoque;

    cin >> consultas;

    for (int i = 0; i < consultas; i++) {
        int pedido;
        cin >> pedido;

        if (estoque.find(pedido) == estoque.end()) {
            estoque.insert(pedido);
            tacos += 2;
        } else {
            estoque.erase(pedido);
        }
    }

    cout << tacos << endl;
    return 0;
}