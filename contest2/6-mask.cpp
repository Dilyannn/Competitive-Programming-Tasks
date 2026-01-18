#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int testCases; cin >> testCases;

    while (testCases--) {
        int strCountN; cin >> strCountN;

        char mask[105]; cin >> mask;
        int starPos = -1;

        for (int i = 0; mask[i]; i++) {
            if (mask[i] == '*') {
                starPos = i;
                break;
            }
        }

        int lenghtOk = starPos;
        int maskLen = strlen(mask);
        int suffLen = maskLen - starPos - 1;

        while (strCountN--) {
            char str[105]; cin >> str;
            int len = strlen(str);

            if (len < lenghtOk + suffLen) {
                cout << "NO" << endl;
                continue;
            }

            bool isOk = true;
            for (int i = 0; i < lenghtOk; i++) {
                if (str[i] != mask[i]) {
                    isOk = false;
                    break;
                }
            }

            if (!isOk) {
                cout << "NO" << endl;
                continue;
            }

            for (int i = 0; i < suffLen; i++) {
                if (str[len - suffLen + i] != mask[maskLen - suffLen + i]) {
                    isOk = false;
                    break;
                }
            }

            if (!isOk) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }

    return 0;
}