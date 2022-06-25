#include <iostream>
#include <stack>

using namespace std;

int main() {
    int lines_n;
    stack<char> chaves;
    bool balanced = true;

    cin >> lines_n;

    for (int i = 0; i < lines_n; i++) {
        string line;
        getline(cin, line);

        for (int j = 0; j < line.length(); j++) {
            if (line[j] == '{') {
                chaves.push('{');
            } else if (line[j] == '}') {
                if (chaves.size() == 0) {
                    balanced = false;
                } else {
                    chaves.pop();
                }
            }
        }
    }

    if (balanced && chaves.size() == 0) {
        cout << 'S' << endl;
    } else {
        cout << 'N' << endl;
    }

    return 0;
}