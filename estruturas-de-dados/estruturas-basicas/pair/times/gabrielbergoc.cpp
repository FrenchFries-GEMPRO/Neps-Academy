// Times
// As aulas de educação física, em muitas escolas, acontecem da seguinte maneira: O professor entrega uma bola ao alunos (geralmente de futebol) e estes se dividem em times, onde jogam partidas alternadamente.

// A maneira como os times são escolhidos também é semelhante em todas as escolas: decide-se quantos times serão formados, e uma pessoa para montar cada um dos times. Cada pessoa vai escolher, alternadamente, um dos alunos restantes para fazer parte de sua equipe. Como todos querem ter uma boa equipe, a pessoa que vai escolher o próximo membro do time escolhe aquele, dentre os ainda disponíveis, que possui o melhor nível de habilidade. Assim, os times acabam ficando relativamente equilibrados na soma do nível de habilidade dos jogadores.

// Dada uma lista de alunos que serão escolhidos e seus respectivos níveis de habilidade para os times e a quantidade de times que serão formados, mostre como ficarão os times ao final do processo de montagem dos mesmos.

// Entrada
// A primeira linha da entrada contém dois inteiros NN e TT, representando respectivamente a quantidade de alunos e o número de times a serem formados, sendo T <= N. As NN linhas seguintes descrevem, cada uma, um aluno disponível para escolha de times. Cada uma dessas linhas possui o nome do aluno (composto apenas por letras minúsculas) e um inteiro HH descrevendo seu nível de habilidade).

// Não existem dois alunos com o mesmo nível de habilidade, e todos eles possuem nomes diferentes. É possível que alguns times acabem ficando com menos jogadores do que os outros.

// Saída
// Seu programa deve imprimir a lista de times que será formada ao final do processo de seleção. Para cada time, você deverá mostrar o termo "Time NN", onde NN é o número do time (1 para o primeiro, 2 para o segundo, e assim por diante) seguido de KK linhas, onde KK é a quantidade de jogadores do time, mostrando o nome de cada um dos jogadores do time, em ordem alfabética. Imprima uma linha em branco após cada descrição de time (inclusive do último).

// Os times serão escolhidos pelo computador, então não é necessário considerar o aluno que irá fazer a escolha dos times.

// Restrições
// 2 <= N <= 10000
// 2 <= T <= 1000
// 0 <= H <= 1000000

// Exemplos de Entrada
// 14 3
// felipe 4
// alvaro 8
// thiago 1
// rodrigo 3
// robson 2
// fabio 9
// ricardo 11
// rodolfo 0
// andre 14
// arthur 12
// ronaldo 55
// rogerio 30
// lucas 7
// rafael 17

// Exemplos de Saída
// Time 1
// andre
// fabio
// felipe
// ronaldo
// thiago
// 
// Time 2
// alvaro
// arthur
// rodolfo
// rodrigo
// rogerio

// Time 3
// lucas
// rafael
// ricardo
// robson

// Exemplos de Entrada
// 4 3
// john 3
// richard 0
// greg 100
// rupert 20

// Exemplos de Saída
// Time 1
// greg
// richard

// Time 2
// rupert

// Time 3
// john

// Traduzido por Luis Paulo

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<pair<int, string>> alunos(N);
    for (int i = 0; i < N; i++) {
        string nome;
        int habilidade;
        cin >> nome >> habilidade;
        alunos[i] = pair(habilidade, nome);
    }

    sort(alunos.rbegin(), alunos.rend());

    vector<string> aux;
    for (int i = 0; i < T; i++) {

        for (int j = 0; i + j < N; j += T) {
            aux.push_back(alunos[i + j].second);
        }

        sort(aux.begin(), aux.end());

        cout << "Time " << i + 1 << endl;
        for (auto a : aux) cout << a << endl;
        cout << endl;

        aux.clear();
    }
}