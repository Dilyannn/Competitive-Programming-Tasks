#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int testCases; cin >> testCases;

    while (testCases--) {
        int squaresCnt; cin >> squaresCnt;
        int max = sqrt(squaresCnt);

        vector<char> alreadyRepeatedS(squaresCnt + 1, 0);
        int count = 0;

        for (int i = 0; i <= max; i++) {
            int isqrt = i * i;
            for (int j = 0; j <= max; j++) {
                int n = isqrt + j * j;

                if (n == 0) continue;
                if (n > squaresCnt) break;

                if (!alreadyRepeatedS[n]) {
                    alreadyRepeatedS[n] = 1;
                    count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}