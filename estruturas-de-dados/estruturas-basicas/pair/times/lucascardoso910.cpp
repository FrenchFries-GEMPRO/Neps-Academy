#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int quant, times;
    vector<pair<int, string>> alunos;

    cin >> quant >> times;

    for (int i = 0; i < quant; i++) {
        pair<int, string> aluno;
        cin >> aluno.second;
        cin >> aluno.first;

        alunos.push_back(aluno);
    }

    sort(
        alunos.begin(), 
        alunos.end(), 
        [](const pair<int, string> &a, const pair<int, string> &b) -> bool {
            if (a.first != b.first) return a.first > b.first;
            else return a.second > b.second;
        }
    );

    vector<vector<string>> formacoes(times);
    for (int i = 0; i < quant; i++) {
        formacoes[i % times].push_back(alunos[i].second);
    }

    for (int i = 0; i < times; i++) {
        sort(formacoes[i].begin(), formacoes[i].end());

        cout << "Time " << i + 1 << endl;

        for (int j = 0; j < formacoes[i].size(); j++) {
            cout << formacoes[i][j] << endl;
        }

        cout << endl;
    }
}