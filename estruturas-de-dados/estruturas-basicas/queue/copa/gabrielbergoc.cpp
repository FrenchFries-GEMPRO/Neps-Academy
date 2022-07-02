// Copa do Mundo (OBI 2010)
// Este ano tem Copa do Mundo! O país inteiro se prepara para torcer para a equipe canarinho conquistar mais um título, tornando-se hexacampeã.

// Na Copa do Mundo, depois de uma fase de grupos, dezesseis equipes disputam a Fase Final, composta de quinze jogos eliminatórios. A figura abaixo mostra a tabela de jogos da Fase Final:


// Figura 1

// Dados os resultados dos quinze jogos da Fase Final, escreva um programa que determine a equipe campeã.

// Entrada
// A entrada é composta de quinze linhas, cada uma contendo o resultado de um jogo. A primeira linha contém o resultado do jogo de número 1, a segunda linha o resultado do jogo de número 2, e assim por diante. O resultado de um jogo é representado por dois números inteiros MM e NN separados por um espaço em branco, indicando respectivamente o número de gols da equipe representada à esquerda e à direita na tabela de jogos.

// Saída
// Seu programa deve imprimir uma única linha, contendo a letra identificadora da equipe campeã.

// Restrições
// 0 \leq N0≤N, M \leq 20M≤20 e M \neq NM
// 
// =N
// Exemplos de Entrada	Exemplos de Saída
// 4 1
// 1 0
// 0 4
// 3 1
// 2 3
// 1 2
// 2 0
// 0 2
// 1 2
// 4 3
// 0 1
// 3 2
// 3 4
// 1 4
// 1 0
// F
// 2 0
// 1 0
// 2 1
// 1 0
// 1 0
// 1 2
// 1 2
// 1 0
// 2 1
// 1 0
// 0 1
// 0 2
// 2 1
// 1 0
// 2 1
// A

#include <iostream>
#include <queue>

using namespace std;

void swap(queue<int>** a, queue<int>** b) {
    queue<int>* aux = *a;
    *a = *b;
    *b = aux;
}

int main () {
    queue<int> q1, q2;
    for (int i = 0; i < 16; i++) q1.push(i);

    queue<int> *p_q = &q1, *p_aux = &q2;

    int M, N, winner;
    while (p_q->size() > 1) {

        while (!p_q->empty()){
            cin >> M >> N;
            if (M > N) {
                winner = p_q->front();
                p_q->pop();
            } else {
                p_q->pop();
                winner = p_q->front();
            }
            p_aux->push(winner);
            p_q->pop();

        }
        
        swap(&p_q, &p_aux);
    }

    std::cout << (char) ('A' + winner) << endl;
}