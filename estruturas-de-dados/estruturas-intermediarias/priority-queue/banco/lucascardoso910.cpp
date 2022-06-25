#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    priority_queue<pair<int, int>> clients;
    pair<int, int> next_client;
    int n_caixas, n_clients;
    
    cin >> n_caixas >> n_clients;
    cin >> next_client.first >> next_client.second;

    int tempo = 0;
    vector<int> caixas(n_caixas);
    for (int i = 0; i < n_caixas; i++) {
        caixas[i] = 0;
    }

    int atrasos = 0;
    while (clients.size() > 0) {
        while (next_client.first == tempo) {
            clients.push(next_client);

            cin >> next_client.first >> next_client.second;
        }
        
        for (int i = 0; i < n_caixas; i++) {
            if (caixas[i] > tempo) continue;
            if (clients.top().first < tempo) continue;
            if (tempo - clients.top().first > 20) atrasos++;
            cout << clients.top().first << " " << clients.top().second << endl;
            caixas[i] = tempo + clients.top().second;
            clients.pop();
        }

        tempo++;
    }

    cout << atrasos << endl;

    return 0;
}