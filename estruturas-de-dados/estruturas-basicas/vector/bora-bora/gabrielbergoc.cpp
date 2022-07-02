/*
REGRAS:
- C < D < H < S
- 12: inverte a ordem
- 7: compra 2 e perde a vez
- 1: compra 1 e perde a vez
- 11: perde a vez
- só pode jogar carta do mesmo número ou mesmo naipe
- carta jogada deve ser a maior possível
- primeira carta da pilha de descarte aplica a possível penalidade ao primeiro 
    jogador
- jogo começa no sentido horário
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;


typedef pair<int,char> card;

bool less_than(card a, card b) {
    if (a.first < b.first) return true;
    if (a.first == b.first && a.second < b.second) return true;
    return false;
}

bool equal(card a, card b) {
    if (a.first != b.first) return false;
    if (a.second != b.second) return false;
    return true;
}

int main() {
    
    while (true) {
        int P, M, N;
        cin >> P >> M >> N;
        if (P == 0) break;

        queue<card> deck;
        for (int i = 0; i < N; i++) {
            int value;
            char suit;
            cin >> value >> suit;

            deck.emplace(value, suit);
        }

        // distribuir mãos
        vector<vector<card>> hands;
        for (int i = 0; i < P; i++) {
            hands.emplace_back();
            for (int j = 0; j < M; j++) {
                hands[i].push_back(deck.front());
                deck.pop();
            }

            sort(hands[i].begin(), hands[i].end(), less_than);

            // for (auto card : hands[i]) {
            //     cout << card.first << " "  << card.second << endl;
            // }
        }

        int dir = 1;            // direção
        int curr_player = 0;    // jogador atual
        card top;               // topo da pilha de descarte

        // virar primeira carta
        top = deck.front();
        deck.pop();
        
        // se no topo há uma dama, inverter direção
        if (top.first == 12) dir *= -1;

        while (true) {

            // se há um 7, comprar 2 e perder a vez
            if (top.first == 7) {
                if (!deck.empty()) {
                    hands[curr_player].push_back(deck.front());
                    deck.pop();
                }
                if (!deck.empty()) {
                    hands[curr_player].push_back(deck.front());
                    deck.pop();
                }
                
                sort(hands[curr_player].begin(), hands[curr_player].end(), less_than);

                curr_player = (curr_player + dir + P) % P;
            }

            // se há um ás, comprar 1 e perder a vez
            else if (top.first == 1) {
                if (!deck.empty()) {
                    hands[curr_player].push_back(deck.front());
                    deck.pop();
                }
                
                sort(hands[curr_player].begin(), hands[curr_player].end(), less_than);

                curr_player = (curr_player + dir + P) % P;
            }

            // se há um valete, perder a vez
            else if (top.first == 11) {
                curr_player = (curr_player + dir + P) % P;
            }

            cout 
                << endl
                << "Top: " << top.first << " " << top.second << endl
                << "Current player: " << curr_player + 1 << endl
                << "Direction: " << dir << endl
                << "Hands:" << endl;
            
            for (auto hand : hands) {
                for (auto c : hand) {
                    cout << c.first << " " << c.second << ", ";
                }
                cout << endl;
            }

            // jogar carta
            top = hands[curr_player].back();
            hands[curr_player].pop_back();

            // verificar se ganhou
            if (hands[curr_player].empty()) break;

            // se no topo há uma dama, inverter direção
            if (top.first == 12) dir *= -1;

            // passar a vez
            curr_player = (curr_player + dir + P) % P;
        }

        cout 
            << endl
            << "Vencedor: " 
            << curr_player + 1 
            << endl 
            << endl;
    }
    
}