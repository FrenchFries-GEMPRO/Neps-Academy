#include <iostream>
#include <vector>

using namespace std;

int main() {
    int pedacos, desejo;

    cin >> pedacos >> desejo;

    int begin;
    int sum = 0;
    int count = 0;
    vector<int> sand;
    for (int i = 0; i < pedacos * 2; i = (i + 1) % pedacos) {
        int ped;
        cin >> ped;
        sand.push_back(ped);
        sum += ped;

        while (begin < i && sum > desejo) {
            sum -= sand[begin];
            begin++;
        }

        if (sum == desejo) {
            count++;

            int aux_begin = begin + 1;
            int aux_sum = sum - sand[begin];

            while (aux_begin < i && aux_sum == desejo) {
                aux_sum -= sand[aux_begin];
                aux_begin++;
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}