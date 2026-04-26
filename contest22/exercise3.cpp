#include <iostream>
#include <string>
using namespace std;

int main() {
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    int prices[7];
    bool first = true;

    while (cin >> prices[0]) {
        for (int i = 1; i < 7; i++) {
            cin >> prices[i];
        }

        if (!first) cout << endl;
        first = false;

        int i = 0;
        while (i < 6) {
            while (i < 6 && prices[i] > prices[i + 1]) i++;
            if (i == 6) break;

            cout << days[i] << " - buy" << endl;

            while (i < 6 && prices[i] < prices[i + 1]) i++;

            cout << days[i] << " - sell" << endl;
        }
    }

    return 0;
}

