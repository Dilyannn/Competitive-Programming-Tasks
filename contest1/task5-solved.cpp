#include <iostream>
using namespace std;

int main() {
    int testsT;
    if (!(cin >> testsT)) return 0;

    while (testsT--) {
        const int modul = 1000000009;
        int n, k;
        cin >> n >> k;

        long long resultArr[1001], arrN[1001];
        int i = 0;
        while (i <= k) {
            resultArr[i] = 0;
            arrN[i] = 0;
            i++;
        }

        resultArr[0] = 1;
        long long sum = 1;

        int pos = 0;
        while (pos < n) {
            const long long prev = resultArr[k];

            arrN[0] = (sum * 20) % modul;
            i = k;
            while (i >= 1) {
                arrN[i] = (resultArr[i-1] * 6) % modul;
                i--;
            }

            i = 0;
            while (i <= k) {
                resultArr[i] = arrN[i];
                arrN[i] = 0;
                i++;
            }

            sum = ((26 * sum) % modul - (6 * prev) % modul + modul) % modul;
            pos++;
        }

        cout << (sum % modul) << endl;
    }
    return 0;
}
