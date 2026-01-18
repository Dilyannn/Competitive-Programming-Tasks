#include <iostream>
#include <vector>
#include <map>
using namespace std;

static constexpr int N = 8;
bool colUsed[N], diag1Used[2*N-1], diag2Used[2*N-1];
int fixedCol[N], solution[N];

bool placeQueen(const int r, const int c, const bool setFlag) {
    const int d1 = r - c + (N - 1);
    const int d2 = r + c;
    if (setFlag) {
        colUsed[c] = true;
        diag1Used[d1] = true;
        diag2Used[d2] = true;
        solution[r] = c;
    } else {
        colUsed[c] = false;
        diag1Used[d1] = false;
        diag2Used[d2] = false;
    }
    return true;
}

bool canPlace(const int r, const int c) {
    const int d1 = r - c + (N - 1);
    const int d2 = r + c;
    return !colUsed[c] && !diag1Used[d1] && !diag2Used[d2];
}

bool solve(const int r) {
    if (r == N) return true;
    if (fixedCol[r] != -1) {
        int c = fixedCol[r];
        if (!canPlace(r, c)) return false;
        placeQueen(r, c, true);
        if (solve(r + 1)) return true;
        placeQueen(r, c, false);
        return false;
    } else {
        for (int c = 0; c < N; ++c) {
            if (canPlace(r, c)) {
                placeQueen(r, c, true);
                if (solve(r + 1)) return true;
                placeQueen(r, c, false);
            }
        }
        return false;
    }
}

int main() {
    for (int i = 0; i < N; ++i) {
        colUsed[i] = false;
        solution[i] = -1;
        fixedCol[i] = -1;
    }
    for (int i = 0; i < 2*N-1; ++i) {
        diag1Used[i] = false;
        diag2Used[i] = false;
    }

    int a, b;
    if (!(cin >> a >> b)) return 0;
    const int r0 = a - 1;
    const int c0 = b - 1;
    if (r0 < 0 || r0 >= N || c0 < 0 || c0 >= N) {
        cout << "Invalid coordinate\n";
        return 0;
    }
    fixedCol[r0] = c0;

    for (int r = 0; r < N; ++r) {
        if (fixedCol[r] != -1) {
            const int c = fixedCol[r];
            if (!canPlace(r, c)) {
                cout << "No solution\n";
                return 0;
            }
            placeQueen(r, c, true);
        }
    }
    for (int r = 0; r < N; ++r) {
        if (fixedCol[r] != -1) {
            const int c = fixedCol[r];
            placeQueen(r, c, false);
            solution[r] = -1;
        }
    }

    if (!solve(0)) {
        cout << "No solution\n";
        return 0;
    }

    int invalid[N][N] = {0};
    for (int r = 0; r < N; ++r) {
        const int qc = solution[r];
        for (int c = 0; c < N; ++c) if (c != qc) invalid[r][c] = 1;
        for (int rr = 0; rr < N; ++rr) if (rr != r) invalid[rr][qc] = 1;
        for (int d = -N; d <= N; ++d) {
            int rr = r + d, cc = qc + d;
            if (rr >= 0 && rr < N && cc >= 0 && cc < N && !(rr == r && cc == qc)) invalid[rr][cc] = 1;
            rr = r + d; cc = qc - d;
            if (rr >= 0 && rr < N && cc >= 0 && cc < N && !(rr == r && cc == qc)) invalid[rr][cc] = 1;
        }
    }

    map<int,int> queens;
    for (int r = 0; r < N; ++r) queens[r + 1] = solution[r] + 1;

    for (const auto & r : invalid) {
        for (int c = 0; c < N; ++c) {
            cout << r[c] << (c + 1 < N ? ' ' : '\n');
        }
    }

    for (auto &p : queens) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
