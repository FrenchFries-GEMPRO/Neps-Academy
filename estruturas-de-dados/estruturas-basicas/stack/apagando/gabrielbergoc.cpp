// Apagando e Ganhando
// Juliano é fã do programa de auditório Apagando e Ganhando, um programa no qual os participantes são selecionados através de um sorteio e recebem prêmios em dinheiro por participarem.

// No programa, o apresentador escreve um número de NN dígitos em uma lousa. O participante então deve apagar exatamente DD dígitos do número que está na lousa; o número formado pelos dígitos que restaram é então o prêmio do participante.

// Juliano finalmente foi selecionado para participar do programa, e pediu que você escrevesse um programa que, dados o número que o apresentador escreveu na lousa, e quantos dígitos Juliano tem que apagar, determina o valor do maior prêmio que Juliano pode ganhar.

// Entrada
// A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém dois inteiros NN e DD, indicando a quantidade de dígitos do número que o apresentador escreveu na lousa e quantos dígitos devem ser apagados. A linha seguinte contém o número escrito pelo apresentador, que não contém zeros à esquerda.

// O final da entrada é indicado por uma linha que contém apenas dois zeros, separados por um espaço em branco.

// Saída
// Para cada caso de teste da entrada seu programa deve imprimir uma única linha na saída, contendo o maior prêmio que Juliano pode ganhar.

// Restrições
// 1 \leq D < N \leq 10^51≤D<N≤10 
// 5
 
// Exemplos de Entrada	Exemplos de Saída
// 4 2
// 3759
// 6 3
// 123123
// 7 4
// 1000000
// 7 3
// 1001234
// 6 2
// 103759
// 0 0
// 79
// 323
// 100
// 1234
// 3759
// Traduzido por Luis Paulo

/**
 * SOLUÇÃO:
 * 1º) Salvar em uma matriz os índices em que ocorrem cada dígito de 0 a 9
 * 2º) Salvar em um vetor os pares { índice, dígito } começando pelas ocorrências de '9' até '0', N - D elementos
 * 3º) Ordenar esse vetor para colocar os dígitos na ordem em que aparecem no número original
 * 4º) Imprimir esse vetor em ordem, apenas o segundo elemento de cada par.
 * 
 * Exemplo 1:
 * 4 2
 * 3759
 * map = { 0: {}, ..., 3: { 0 }, ..., 5: { 2 }, ..., 7: { 1 }, ... 9: { 3 } }
 * digits = { { 3, 9 }, { 1, 7 } }
 * *sort*
 * digits = { { 1, 7 }, { 3, 9 } }
 * for (auto d : digits) cout << d.second;
 * cout << endl;
 * 
 * Saída: 79
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int N, D;
    while (true) {
        cin >> N >> D;
        if (N == 0 && D == 0) break;

        string number;
        cin >> number;

        vector<vector<int>> map (10);
        for (int i = 0; i < number.size(); i++) {
            map[(int) (number[i] - '0')].push_back(i);
        }

        int count = 0;
        vector<pair<int, int>> digits;
        for (int i = map.size() - 1; i >= 0; i--) {
            for (int j = map[i].size() - 1; j >= 0 ; j--) {
                digits.push_back(make_pair(map[i][j], i));
                count++;
                if (count == N - D) break;
            }
            if (count == N - D) break;
        }

        sort(digits.begin(), digits.end());

        for (int i = 0; i < digits.size(); i++) {
            cout << digits[i].second;
        }
        cout << endl;

    }
}