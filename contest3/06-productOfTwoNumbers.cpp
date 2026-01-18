#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long M;
    while (cin >> M) {
        long long A = -1, B = -1;

        for (long long i = 2; i * i <= M; i++) {
            if (M % i == 0) {
                A = i;
                B = M / i;
                break;
            }
        }

        if (A > B) swap(A, B);  //a < b vinagi
        cout << A << " " << B << endl;
    }

    return 0;
}
