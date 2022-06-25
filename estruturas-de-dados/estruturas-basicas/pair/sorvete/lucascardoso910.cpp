#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<pair<int, int>> intervals;
    int comp, sorv;

    cin >> comp >> sorv;

    for (int i = 0; i < sorv; i++) {
        pair<int, int> interval;
        cin >> interval.first;
        cin >> interval.second;

        bool inserted = false;
        for (int j = 0; j < intervals.size(); j++) {
            // cout << "Comparing:" << endl;
            // cout << interval.first << " " << interval.second << endl;
            // cout << intervals[j].first << " " << intervals[j].second << endl;
            // cout << endl;

            if (interval.second < intervals[j].first) {
                // cout << "Inserting interval before!" << endl;
                intervals.insert(intervals.begin() + j, interval);
                inserted = true;
            } else if (interval.second >= intervals[j].first && interval.second <= intervals[j].second) {
                if (intervals[j].first > interval.first) {
                    // cout << "Inserting at the begin of the interval" << endl;
                    intervals[j].first = interval.first;
                }
                inserted = true;
            } else if (interval.first >= intervals[j].first && interval.first <= intervals[j].second) {
                if (intervals[j].second < interval.second) {
                    // cout << "Inserting at the end of the interval" << endl;
                    intervals[j].second = interval.second;
                }
                inserted = true;
            }

            if (inserted) {
                break;
            }
        }

        if (!inserted) {
            // cout << "Inserting after all intervals" << endl;
            intervals.push_back(interval);
        }

        // cout << endl;
    }

    for (int i = 0; i < intervals.size() - 1; i++) {
        if (intervals[i].second >= intervals[i + 1].first) {
            intervals[i].second = intervals[i + 1].second;
            intervals.erase(intervals.begin() + i + 1);
        }
    }

    for (int i = 0; i < intervals.size(); i++) {
        cout << intervals[i].first << " " << intervals[i].second << endl;
    }
    // cout << endl;

    return 0;
}