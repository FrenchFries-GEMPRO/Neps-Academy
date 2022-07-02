#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<int> sanduiche(N);
    for (int i = 0; i < N; i++) cin >> sanduiche[i];

    int r = 0;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        while (r < i + N && sum < D) {
            sum += sanduiche[r % N];
            r++;
        }

        if (sum == D) count++;

        sum -= sanduiche[i];
    }

    cout << count << endl;
}
