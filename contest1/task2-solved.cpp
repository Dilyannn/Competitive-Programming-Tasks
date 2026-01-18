#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        istringstream in(line);

        int a;
        int b;
        if (!(in >> a >> b)) continue;

        int c[11];
        int n = 0;
        int tmp;
        while (in >> tmp && n < 11) {
          c[n++] = tmp;
        }
        
        if (n == 0) continue;
        if (a > b) swap(a, b);

        auto lambdaChecker = [&](int x) {
            int result = 0;
            for (int i = n - 1; i >= 0; --i) {
              result = result * x + c[i];
            }
            return result;
        };

        int mn = lambdaChecker(a), mx = mn;
        for (int x = a + 1; x <= b; x++) {
            int var = lambdaChecker(x);
            if (var < mn) {
              mn = var;
            }
            if (var > mx) {
              mx = var;
            }
        }
        cout << mn << ' ' << mx << endl;
    }
}
