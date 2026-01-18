#include <iostream>
using namespace std;

const int MAX_K_constrains = 13000;
const int MAX_N_constrains = 10000000;

int bottlesArrCnt[MAX_N_constrains + 1], counterr[MAX_K_constrains + 1];

int main() {
    int testCases;
    if (!(cin >> testCases)) return 0;

    while (testCases--) {
        int nBottlesRow, kDiffTypes;
        cin >> nBottlesRow >> kDiffTypes;

        for (int i = 0; i < nBottlesRow; i++) cin >> bottlesArrCnt[i];
        for (int i = 1; i <= kDiffTypes; i++) counterr[i] = 0;

        int haveTypes = 0;
        int bestCaseRow = nBottlesRow + 1;
        int best1 = 0, best2 = nBottlesRow - 1;

        int lenght = 0;
        for (int i = 0; i < nBottlesRow; i++) {
            int type2 = bottlesArrCnt[i];
            if (counterr[type2] == 0) ++haveTypes;
            ++counterr[type2];

            while (haveTypes == kDiffTypes) {
                int len = i - lenght + 1;
                if (len < bestCaseRow) {
                    bestCaseRow = len;
                    best1 = lenght;
                    best2 = i;
                }

                int type1 = bottlesArrCnt[lenght];
                --counterr[type1];
                if (counterr[type1] == 0) --haveTypes;
                ++lenght;
            }
        }
        cout << (best1 + 1) << " " << (best2 + 1) << endl;
    }

    return 0;
}
