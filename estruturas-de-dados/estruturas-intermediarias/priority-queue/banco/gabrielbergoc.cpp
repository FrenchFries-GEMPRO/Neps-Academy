#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    // n. de caixas, 
    // n. de clientes, 
    // n. de clientes que esperaram mais de 20 minutos
    int C, N, count = 0;
    cin >> C >> N;
    
    // caixas liberados em ordem crescente de tempo
    priority_queue<int, vector<int>, greater<int>> caixas;
    for (int i = 0; i < C; i++) {
        caixas.push(0);
    }
    
    for (int i = 0; i < N; i++) {
        
        // horário de chegada do cliente, 
        // duração do atendimento do cliente, 
        // horário que o próximo caixa vai ser liberado
        int chegada, duracao, liberado;
        cin >> chegada >> duracao;
        liberado = caixas.top();
        caixas.pop();
        
        // se o tempo que o caixa foi liberado menos o tempo de chegada do 
        // cliente for maior que 20 minutos, ele esperou mais de 20 minutos
        // para ser atendido
        if (liberado - chegada > 20) { count++; }

        // o próximo cliente vai ser atendido, e colocamos na priority_queue
        // o horário em que o caixa vai ficar livre, que é o tempo que o caixa
        // ficou livre + duração do atendimento (caso em que o cliente esperou
        // para ser atendido) ou tempo que o cliente chegou + duração do
        // atendimento (caso em que o caixa ficou ocioso até a chegada de um
        // cliente)
        caixas.push(max(chegada, liberado) + duracao);

    }

    cout << count << endl;
}