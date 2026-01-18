#include <iostream>
#include <vector>
using namespace std;

long long countRoutes(int xm, int ym, int height) {
    int steps = xm - 2;
    if (steps < 0) return 0;

    int yMin = -50, yMax = 50, shift = -yMin, ySize = yMax - yMin + 1;

    vector<vector<vector<long long>>> p(steps + 1,
        vector<vector<long long>>(ySize, vector<long long>(height + 1, 0)));

    auto yy = [&](int y) { return y >= yMin && y <= yMax; };

    p[0][0 + shift][1] = 1;

    for (int i = 0; i < steps; i++) {
        for (int j = yMin; j <= yMax; j++) {
            for (int k = 1; k <= height; k++) {
                long long current = p[i][j + shift][k];

                if (!current) {
                    continue;
                }

                for (int dy : {-1, 0, 1}) {
                    int ny = j + dy;
                    if (!yy(ny)) continue;

                    p[i + 1][ny + shift][k] += current;

                    if (k < height) {
                        p[i + 1][ny + shift][k + 1] += current;
                    }

                    if (k > 1) {
                        p[i + 1][ny + shift][k - 1] += current;
                    }
                }
            }
        }
    }

    if (!yy(ym)) {
        return 0;
    }

    return p[steps][ym + shift][1];
}

int main() {
    int xm, ym, height;
    while (cin >> xm >> ym >> height) {
        cout << countRoutes(xm, ym, height) << "\n";
    }
    return 0;
}