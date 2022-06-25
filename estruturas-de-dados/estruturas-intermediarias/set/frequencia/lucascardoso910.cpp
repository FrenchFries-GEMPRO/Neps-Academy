#include <iostream>
#include <set>

using namespace std;

int main() {
    int registers;
    set<int> students;

    cin >> registers;

    for (int i = 0; i < registers; i++) {
        int student;
        cin >> student;
        students.insert(student);
    }

    cout << students.size() << endl;
    return 0;
}