#include <iostream>

#define MAXN (int) 1E5 + 1

using namespace std;

int leader[MAXN] = {0};
int score[MAXN];

int find(int x) {
    if (x == leader[x]) return x;
    
    // otimização: atribuir o líder da guilda como líder de x;
    // transforma a consulta em O(1)
    leader[x] = find(leader[x]);
    return leader[x];
}

void join(int x, int y) {

    // juntar apenas os líderes de cada guilda
    x = find(x);
    y = find(y);
    if (x == y) return;

    leader[x] = y;
    score[y] += score[x];
}

int main() {
    int N, M;

    while (true) {
        int victories = 0;

        cin >> N >> M;

        if (N == 0 && M == 0) break;

        for (int i = 1; i <= N; i++) {
            leader[i] = i;
            cin >> score[i];
        }

        for (int q, a, b, i = 0; i < M; i++) {
            cin >> q >> a >> b;
            if (q == 1) {
                join(a, b);
            } else {

                // comparar os líderes de cada guilda
                a = find(a);
                b = find(b);

                int winner = 0;
                if (score[a] > score[b]) winner = a;
                else if (score[a] < score[b]) winner = b;

                // incrementar o número de vitórias apenas se for a guilda do 
                // rafael
                if (find(winner) == find(1)) victories++;
            }
        }

        cout << victories << endl;
    }
}