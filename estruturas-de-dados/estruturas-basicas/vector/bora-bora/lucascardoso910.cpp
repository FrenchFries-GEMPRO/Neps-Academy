#include <bits/stdc++.h>

#if 1
#define print(x) cout << x << endl
#else 
#define print(x)
#endif

using namespace std;

#typedef pair<int, char> tipoCarta

int main() {
    int jogadores, cartas_mao, cartas_baralho;
    vector<tipoCarta> baralho;

    cin >> jogadores;
    cin >> cartas_mao;
    cin >> cartas_baralho;

    for (int i = 0; i < cartas_baralho; i++) {
        tipoCarta carta;

        cin >> carta.first >> carta.second;
        baralho.push_back(carta);
    }

    vector<vector<tipoCarta>> cartas_jogadores;
    stack<tipoCarta> descarte;
    stack<tipoCarta> compra;

    for (int i = 0; i < jogadores; i++) {
        vector<tipoCarta> cartas;
        for (int j = 0; j < cartas_mao; j++) {
            cartas.push_back(baralho[0]);
            baralho.erase(baralho.begin());
        }
        sort(cartas.begin(), cartas.end(), [](const tipoCarta& a, const tipoCarta& b) -> bool {
            if (a.first != b.first) return a.first < b.first;
            else return a.second < b.second;
        });

        cartas_jogadores.push_back(cartas);
    }

    descarte.push(baralho[0]);
    baralho.erase(baralho.begin());

    while (baralho.size() > 0) {
        tipoCarta carta = baralho.back();
        compra.push(carta);
        baralho.pop_back();
    }

    bool end = false;
    int jogador = 0;
    int sentido = 1;
    while (!end) {
        print(jogador);
        tipoCarta topo = descarte.top();
        print(topo.first);

        if (topo.first == 12) {
            print("Jogo invertido");
            jogador -= 2 * sentido;
            sentido *= -1;
        } else if (topo.first == 7) {
            print("Jogador comprou 2");
            tipoCarta carta;

            carta = compra.top();
            cartas_jogadores[jogador].push_back(carta);
            compra.pop();

            carta = compra.top();
            cartas_jogadores[jogador].push_back(carta);
            compra.pop();

            jogador += sentido;

            if (jogador == -1) {
                jogador = jogadores - 1;
            }

            if (jogador == jogadores) {
                jogador = 0;
            }
        } else if (topo.first == 1) {
            tipoCarta carta;

            carta = compra.top();
            cartas_jogadores[jogador].push_back(carta);
            compra.pop();

            jogador += sentido;

            if (jogador == -1) {
                jogador = jogadores - 1;
            }

            if (jogador == jogadores) {
                jogador = 0;
            }
        } if (topo.first == 11) {
            jogador += sentido;

            if (jogador == -1) {
                jogador = jogadores - 1;
            }

            if (jogador == jogadores) {
                jogador = 0;
            }
        }

        bool tinha_carta = false;
        for (int i = 0; i < cartas_jogadores[jogador].size(); i++) {
            tipoCarta carta = cartas_jogadores[jogador][i];
            if (carta.first == topo.first || carta.second == topo.second) {
                descarte.push(carta);
                cartas_jogadores[jogador].erase(cartas_jogadores[jogador].begin() + i);
                tinha_carta = true;
            }
        }
        if (!tinha_carta) {
            tipoCarta carta = compra.top();
            compra.pop();
            cartas_jogadores[jogador].insert(upper_bound(cartas_jogadores[jogador].begin(), cartas_jogadores[jogador].end(), carta));

            if (carta.first == topo.first || carta.second == topo.second) {
                descarte.push(carta);
                cartas_jogadores[jogador].erase(cartas_jogadores[jogador].begin() + cartas_jogadores[jogador].size() - 1);
            }
        }

        if (cartas_jogadores[jogador].size() == 0) {
            end = true;
        } else {
            jogador += sentido;

            if (jogador == -1) {
                jogador = jogadores - 1;
            }

            if (jogador == jogadores) {
                jogador = 0;
            }
        }
    }

    cout << jogador + 1 << endl;

    return 0;
}