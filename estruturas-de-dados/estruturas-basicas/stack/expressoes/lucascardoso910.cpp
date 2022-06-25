#include <iostream>
#include <stack>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    for (int i = 0; i < tests; i++) {
        stack<char> expressao;
        string expression;

        cin >> expression;

        for (int j = 0; j < expression.length(); j++) {
            if (expressao.size() == 0) {
                expressao.push(expression[j]);
                continue;
            }

            if (abs(expressao.top() - expression[j]) <= 2 && expression[j] - expressao.top() > 0) {
                expressao.pop();
            } else {
                expressao.push(expression[j]);
            }
        }

        if (expressao.size() == 0) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}