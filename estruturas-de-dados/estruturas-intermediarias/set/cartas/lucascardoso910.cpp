#include <iostream>
#include <set>

using namespace std;

int main() {
    int alice_cards, beatriz_cards;
    set<int> alice;
    set<int> beatriz;

    cin >> alice_cards >> beatriz_cards;

    for (int i = 0; i < alice_cards; i++) {
        int card;
        cin >> card;

        alice.insert(card);
    }

    for (int i = 0; i < beatriz_cards; i++) {
        int card;
        cin >> card;

        beatriz.insert(card);
    }

    int counter = 0;
    if (alice.size() > beatriz.size()) {
        for (set<int>::iterator it = beatriz.begin(); it != beatriz.end(); it++) {
            if (alice.find(*it) == alice.end()) {
                counter++;
            }
        }
    }
    else {
        for (set<int>::iterator it = alice.begin(); it != alice.end(); it++) {
            if (beatriz.find(*it) == beatriz.end()) {
                counter++;
            }
        }
    }

    cout << counter << endl;

    return 0;
}