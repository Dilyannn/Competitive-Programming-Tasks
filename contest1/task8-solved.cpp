#include <iostream>
using namespace std;

int C[50][7];

int toto(const int a[6]) {
    int result  = 0, prev = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = prev + 1; j <= a[i] - 1; j++) {
            result += C[49 - j][5 - i];
        }
        prev = a[i];
    }
    return result;
}

int main() {
    for (int i = 0; i < 50; i++) {
        C[i][0] = 1;

        for (int j = 1; j < 7; j++) {
            if (j > i) {
                C[i][j] = 0;
            }
            else if (j == i) {
                C[i][j] = 1;
            }
            else {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            }
        }
    }

    int a[6], b[6];
    while (cin >> a[0]) {
        for (int i = 1; i < 6; i++) {
            cin >> a[i];
        }
        for (int & i : b) {
            cin >> i;
        }
        
        const int setA = toto(a), setB = toto(b);
        
        cout << (setB - setA - 1) << endl;
    }
    return 0;
}
