#include <iostream>
#include <string>
using namespace std;

struct Day {
    string name;
};

int main() {
    Day days[] = {
        {"Monday"},
        {"Tuesday"},
        {"Wednesday"},
        {"Thursday"},
        {"Friday"},
        {"Saturday"},
        {"Sunday"}
    };

    int aP[7];
    bool flag = true;

    while (cin >> aP[0]) {
        int j = 1;
        while (j < 7) {
            cin >> aP[j];
            j++;
        }

        if (!flag) cout << endl;
        flag = false;

        int i = 0;
        while (i < 6) {
            while (i < 6 && aP[i] > aP[i + 1]) i++;
            if (i == 6) break;

            cout << days[i].name << " - buy" << endl;

            while (i < 6 && aP[i] < aP[i + 1]) i++;

            cout << days[i].name << " - sell" << endl;
        }
    }

    return 0;
}

