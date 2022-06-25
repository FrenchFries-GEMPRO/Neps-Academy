#include <iostream>
#include <queue>

using namespace std;

int main() {
    char times_letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
    queue<char> times;

    for (int i = 0; i < 16; i++) {
        times.push(times_letters[i]);
    }

    for (int i = 0; i < 15; i++) {
        int gols1, gols2, sg;
        char time1, time2;

        time1 = times.front();
        times.pop();

        time2 = times.front();
        times.pop();

        cin >> gols1 >> gols2;
        sg = gols1 - gols2;

        if (sg > 0) {
            times.push(time1);
        } else {
            times.push(time2);
        }
    }

    cout << times.front() << endl;

    return 0;
}