#include <iostream>
#include <string>
using namespace std;

int main() {
    int tests;
    if (!(cin >> tests)) return 0;

    while (tests--) {
        string str; cin >> str;

        long long c2 = 0, c20 = 0, c201 = 0, c2017 = 0;

        for (char charactrer : str) {
            switch (charactrer) {
              case '7':  c2017 += c201;
                break;
              case '1': c201 += c20;
                break;
              case '0': c20 += c2;
                break;
              case '2': c2++;
                break;
              default: ;
                break;
            }
        }

        cout << c2017 << endl;
    }

    return 0;
}