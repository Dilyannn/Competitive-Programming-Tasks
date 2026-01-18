#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXMAXMAX = 1e9;

int hausdorfInit(
    const vector<pair<int,int>>& first,
    const vector<pair<int,int>>& second,
    int rows, int cols
) {
    vector<vector<int>> d(rows, vector<int>(cols, MAXMAXMAX));
    queue<pair<int,int>> bfs;

    const int directionXX[8] = {0, 0, -1, 1, -1, -1, 1, 1};
    const int directionYY[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

    for (const auto& p : second) {
        d[p.first][p.second] = 0;
        bfs.push(p);
    }

    while (!bfs.empty()) {
        auto [y, x] = bfs.front();
        bfs.pop();

        for (int i = 0; i < 8; ++i) {
            int ny = y + directionYY[i], nx = x + directionXX[i];

            if (ny >= 0 && ny < rows && nx >= 0 && nx < cols) {
                if (d[ny][nx] > d[y][x] + 1) {
                    d[ny][nx] = d[y][x] + 1;
                    bfs.push({ny, nx});
                }
            }
        }
    }

    int ultimateMaxMaxDistance = 0;
    for (const auto& p : first) {
        ultimateMaxMaxDistance = max(ultimateMaxMaxDistance, d[p.first][p.second]);
    }

    return ultimateMaxMaxDistance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int r, c; cin >> r >> c;
        if (!cin || (r == 0 && c == 0)) break;

        vector<pair<int,int>> setA, setB;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int val;
                cin >> val;
                if (val) setA.emplace_back(i, j);
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int val; cin >> val;
                if (val) setB.emplace_back(i, j);
            }
        }

        int d1 = hausdorfInit(setA, setB, r, c), d2 = hausdorfInit(setB, setA, r, c);
        cout << max(d1, d2) << endl;
    }

    return 0;
}