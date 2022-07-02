#include <iostream>
#include <unordered_map>
#include <sstream>
#include <fstream>

#define DEBUG 0
#if DEBUG
    #define print(x) cout << x << endl
    #define out(x) cout << ""
#else
    #define print(x) cout << ""
    #define out(x) cout << x
#endif

using namespace std;

int main() {

    ofstream ofs;
    ofs.open("out", ofstream::out | ofstream::trunc);
    ofs.close();

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int M, N;
        cin >> M >> N;
        string b;
        getline(cin, b);

        // pegando palavras e suas traduções
        unordered_map<string,string> dict;
        for (int i = 0; i < M; i++) {
            string og, tr;
            getline(cin, og);
            getline(cin, tr);
            dict[og] = tr;
            // print(og);
            // print(tr);
        }

        // pegando a letra da música
        for (int i = 0; i < N; i++) {
            string buff;
            getline(cin, buff);

            string word;
            istringstream iss(buff);
            // imprimindo a tradução
            while (getline(iss, word, ' ')) {

                if (dict.find(word) != dict.end()) {
                    out(dict[word]);
                    out(" ");
                } else {
                    out(word);
                    out(" ");
                }

            }
                
            out("\n");
        }
        
        out("\n");
    }
}