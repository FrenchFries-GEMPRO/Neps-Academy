#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int instances;

    cin >> instances;

    for (int i = 0; i < instances; i++) {
        map<string, string> japan_brazil;
        int dict_size, music_size;

        scanf("%d %d\n", &dict_size, &music_size);

        for (int j = 0; j < dict_size; j++) {
            string japan;
            string brazil;

            getline(cin, japan);
            getline(cin, brazil);

            japan_brazil[japan] = brazil;
        }

        for (int j = 0; j < music_size; j++) {
            string translation;
            string music_line;
            string word;

            getline(cin, music_line);

            for (int k = 0; k < music_line.length(); k++) {
                if (music_line[k] == ' ') {
                    translation = japan_brazil[word];

                    if (translation.empty()) {
                        cout << word << ' ';
                    } else {
                        cout << translation << ' ';
                    }

                    word = "";
                } else {
                    word += music_line[k];
                }
            }

            translation = japan_brazil[word];
            if (translation.empty()) {
                cout << word << endl;
            } else {
                cout << translation << endl;
            }
        }
    }

    return 0;
}