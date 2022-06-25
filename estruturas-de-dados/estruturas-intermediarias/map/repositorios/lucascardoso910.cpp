#include <iostream>
#include <map>

using namespace std;

int main() {
    int comp, net;
    map<int, int> instalados;
    map<int, int> instalar;

    cin >> comp >> net;

    for (int i = 0; i < comp; i++) {
        int programa, versao;
        cin >> programa >> versao;
        instalados[programa] = versao;
    }

    for (int i = 0; i < net; i++) {
        int programa, versao;
        int versao_instalada;

        cin >> programa >> versao;
        versao_instalada = instalados[programa];

        if (!versao_instalada || versao > versao_instalada) {
            int versao_marcada = instalar[programa];
            if (versao_marcada) versao = max(versao, versao_marcada);
            instalar[programa] = versao;
        }
    }

    for (map<int, int>::iterator it = instalar.begin(); it != instalar.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}