#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    // guardar o n. de ligações de cada atendente
    vector<int> contadores(N + 1, 0);

    // fila que dá prioridade a quem ficar livre primeiro, depois a quem tiver
    // o menor id
    priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>, 
            greater<pair<int, int>>
        > atendentes;
    
    // fila começa com todos os atendentes livres
    for (int i = 1; i <= N; i++) {
        atendentes.emplace(0, i);
    }

    // para cada ligação
    for (int i = 0; i < L; i++) {
        
        // duração da ligação no topo da lista
        int duracao;
        cin >> duracao;

        // atribuir a quem tiver prioridade
        int t_livre = atendentes.top().first;
        int id_livre = atendentes.top().second;
        atendentes.pop();
        atendentes.emplace(duracao + t_livre, id_livre);
        contadores[id_livre]++;

    }

    for (int i = 1; i <= N; i++) {
        cout << i << " " << contadores[i] << endl;
    }

}