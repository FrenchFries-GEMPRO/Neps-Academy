#include <bits/stdc++.h>

using namespace std;

int main() {
    int initial_size;
    int leaving_size;
    vector<int> people;

    cin >> initial_size;

    for (int i = 0; i < initial_size; i++) {
        int person;

        cin >> person;

        people.push_back(person);
    }

    cin >> leaving_size;

    for (int i = 0; i < leaving_size; i++) {
        int leaving;

        cin >> leaving;

        for (int j = 0; j < people.size(); j++) {
            if (people[j] == leaving) {
                people.erase(people.begin() + j);
                break;
            }
        }
    }

    for (int i = 0; i < people.size(); i++) {
        cout << people[i] << " ";
    }
    cout << endl;

    return 0;
}