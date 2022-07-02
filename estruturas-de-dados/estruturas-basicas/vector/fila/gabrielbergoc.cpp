// Fila (OBI2014)
// Com a proximidade da Copa do Mundo, o fluxo de pessoas nas filas para compra de ingressos aumentou consideravelmente. Como as filas estão cada vez maiores, pessoas menos pacientes tendem a desistir da compra de ingressos e acabam deixando as filas, liberando assim vaga para outras pessoas. Quando uma pessoa deixa a fila, todas as pessoas que estavam atrás dela dão um passo a frente, sendo assim nunca existe um espaço vago entre duas pessoas. A fila inicialmente contém NN pessoas, cada uma com um identificador diferente. Joãozinho sabe o estado inicial dela e os identificadores em ordem das pessoas que deixaram a fila. Sabendo que após o estado inicial nenhuma pessoa entrou mais na fila, Joãozinho deseja saber o estado final da fila.

// Entrada
// A primeira linha contém um inteiro NN representando a quantidade de pessoas inicialmente na fila. A segunda linha contém NN inteiros representando os identificadores das pessoas na fila. O primeiro identificador corresponde ao identificador da primeira pessoa na fila. É garantido que duas pessoas diferentes não possuem o mesmo identificador. A terceira linha contém um inteiro MM representando a quantidade de pessoas que deixaram a fila. A quarta linha contém MM inteiros representando os identificadores das pessoas que deixaram a fila, na ordem em que elas saíram. É garantido que um mesmo identificador não aparece duas vezes nessa lista.

// Saída
// Seu programa deve imprimir uma linha contendo N - MN−M inteiros com os identificadores das pessoas que permaneceram na fila, em ordem de chegada.

// Restrições
// 1 <= N <= 50000
// 1 <= M <= 50000 e M < N
// Cada identificador está entre 11 e 100000100000.
// Exemplos de Entrada
// 8
// 5 100 9 81 70 33 2 1000
// 3
// 9 33 5
// 100 81 70 2 1000
// 4
// 10 9 6 3
// 1
// 3
// Exemplos de Saída
// 10 9 6
// Traduzido por Matheus Henrique

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int N, M;
	cin >> N;
	
	vector<int> queue(N);
	unordered_map<int, int> map;
	for (int i = 0; i < N; i++) {
		cin >> queue[i];
		map.insert({queue[i], i});
	}
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		queue[map[x]] = 0;
	}
	
	for (int i = 0; i < queue.size(); i++) {
		if (queue[i]) cout << queue[i] << " ";
	}
	
	cout << endl;
}