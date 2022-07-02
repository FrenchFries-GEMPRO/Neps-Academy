/* Bora Bora
Bora Bora é um jogo de cartas simples para crianças, inventado na Ilha do Pacífico Sul de mesmo nome. Duas ou mais pessoas podem jogar, usando um baralho de cartas normais. As cartas têm os valores normais: Ás, 2, 3, 4, 5, 6, 7, 8, 9, 10, Valete, Dama e Rei. Cada carta tem também um dos quatro naipes: Paus, Ouros, Copas e Espadas.

Os jogadores sentam-se em um círculo ao redor da mesa e jogam por turnos. O próximo jogador a jogar pode ser aquele à esquerda (sentido horário) ou o jogador à direita (sentido anti-horário) do jogador atual, dependendo das cartas jogadas, como você verá. No começo, o sentido do jogo é horário.

O baralho é embaralhado e é dada a cada jogador uma mão de cartas. O restante do baralho é colocado na mesa, virado para baixo; a essa pilha é dado o nome de pilha de saque. Então a primeira (a mais acima) carta é removida da pilha e colocada na mesa, virada para cima, começando outra pilha, chamada de pilha de descarte.

O objetivo do jogo é que um jogador descarte todas suas cartas. Em cada turno, um jogador descarta no máximo uma carta. Uma carta pode ser descartada apenas se ela tem o mesmo valor ou o mesmo naipe da carta que se encontra no topo da pilha de descarte. Um jogador descarta uma carta colocando-a, virada para cima, na pilha de descarte (essa carta se torna a carta do topo). Se um jogador não tiver uma carta passível de ser descartada em seu turno, ele deve sacar uma carta da pilha de saque e adicionar à sua mão; se ele puder descartar essa carta, ele o faz, caso contrário ele não faz mais nada e seu turno acaba. Um jogador sempre descarta a carta mais alta que ele consegue. O valor de uma carta é determinado primeiro pelo valor da carta e então pelo naipe. A ordem dos valores é o valor em si (Ás é o menor e Rei é o maior), e a ordem dos naipes é, do menor para o maior, Paus, Ouros, Copas e Espadas. Portanto, a carta de maior valor é o Rei de Espadas e a de menor valor é o Ás de Paus. Como exemplo, a Dama de Ouros tem um valor maior que um Valete (qualquer naipe) mas tem um valor menor que a Dama de Copas.

Algumas das cartas descartadas afetam o jogo, como se segue:

Quando uma Dama é descartada, a direção de jogo é invertida: se a direção é horária, ela se torna anti-horária, e vice-versa;
Quando um Sete é descartado, o próximo jogador deve sacar duas cartas da pilha de saque (o número de cartas em sua mão aumenta por dois), e perde a vez (não descarta nenhuma carta);
Quando um Ás é descartado, o próximo jogador deve sacar uma carta da pilha de saque (o número de cartas em sua mão aumenta por um), e perde sua rodada (não descarta nenhuma carta);
Quando um Valete é descartado, o próximo jogador perde a vez (não descarta nenhuma carta).
Perceba que a penalidade da primeira carta da pilha de descarte (a carta sacada da pilha de saque no começo) é aplicada ao primeiro jogador a jogar. Por exemplo, se o primeiro jogador é pp e a primeira carta na pilha de descarte é um Ás, o jogador pp saca uma carta da pilha de saque e não descarta nenhuma carta em seu primeiro turno. Note também que se a primeira carta é uma Dama, o sentido do jogo é invertido para o anti-horário, mas o primeiro jogador a jogar permanece o mesmo.

O vencedor é o jogador que descarta todas suas cartas primeiro (o jogo acaba depois de o vencedor descartar sua última carta).

Dada a descrição do baralho embaralhado e o número de jogadores, escreva um programa que determine quem vencerá o jogo.

Entrada
A entrada contém diversos casos de teste. A primeira linha de um caso de teste contém três inteiros PP, MM e NN, separados por espaço, indicando respectivamente o número de jogadores, o número de cartas distribuídas para cada jogador no começo da partida e o número de cartas no baralho embaralhado. Cada uma das próximas NN linhas contém a descrição de uma carta. Uma carta é descrita por um inteiro X e um caractere S, separados por um espaço, representando respectivamente o valor da carta e seu naipe. O valor das cartas é mapeado com inteiros de 1 a 13 (Ás é 1, Valete é 11, Dama é 12 e Rei é 13). Os naipes das cartas são designados pela primeira letra do naipe: 'C' (Paus - Clubs), 'D' (Ouros - Diamonds), 'H' (Copas - Hearts) ou 'S' (Espadas - Spades).

Os jogadores são identificados com valores de 1 a PP e sentam-se em um círculo, no sentido horário, 1, 2 \ldots P1,2…P, 1. As primeiras PP x MM cartas do baralho são distribuídas aos jogadores: as primeiras MM cartas ao primeiro jogador (jogador 1), as próximas MM cartas ao segundo jogador (jogador 2), e assim por diante. Depois de distribuir as cartas aos jogadores, a próxima carta do baralho - a (PP x MM + 1)-ésima carta - é usada para começar a pilha de descarte, e as cartas restantes formam a pilha de saque. A (PP x MM + 2)-ésima carta a aparecer na entrada é a carta do topo da pilha de saque, e a última carta a aparecer na entrada (a N-ésima carta) é a carta de baixo da pilha de saque (a última carta que pode ser sacada). O jogador 1 é sempre o primeiro a jogar (mesmo se a carta usada para começar a pilha de descarte é uma Dama). Todos os casos de teste têm um vencedor, e em todos casos de teste o número de cartas no baralho é suficiente para jogar até o fim da partida.

O final da entrada é indicado por uma linha contendo apenas três zeros, separados por espaços.

Saída
Para cada caso de teste na entrada, seu programa deve imprimir uma única linha, contendo o número do jogador que ganha a partida.

Restrições
2 <= P <= 10
1 <= M <= 11
3 <= N <= 300
Exemplos de Entrada
2 2 10
1 D
7 D
1 S
3 C
13 D
1 S
5 H
12 D
7 S
2 C
3 2 11
1 S
7 D
11 D
3 D
7 D
3 S
11 C
8 C
9 H
6 H
9 S
3 3 16
1 H
10 C
13 D
7 C
10 H
2 S
2 C
10 S
8 S
12 H
11 C
1 C
1 C
4 S
5 D
6 S
0 0 0
Exemplos de Saída
1
3
2
Traduzido por Luis Paulo

REGRAS:
- C < D < H < S
- 12: inverte a ordem
- 7: compra 2 e perde a vez
- 1: compra 1 e perde a vez
- 11: perde a vez
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

bool greater_than(pair<int, char> a, pair<int, char> b) {
    if (a.first > b.first) return true;
    if (a.first == b.first && a.second > b.second) return true;
    return false;
}

bool equal(pair<int, char> a, pair<int, char> b) {
    if (a.first != b.first) return false;
    if (a.second != b.second) return false;
    return true;
}

int main() {
    
    while (true) {
        int P, M, N;
        cin >> P >> M >> N;
        if (P == 0) break;

        queue<pair<int, char>> deck;
        for (int i = 0; i < N; i++) {
            int value;
            char suit;
            cin >> value >> suit;

            deck.emplace(value, suit);
        }
    }
    
}