#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

static long double round2(long double x) {
    return floor(x * 100.0L + 0.5L) / 100.0L;
}

int main() {
    int R; cin >> R;

    for (int region = 1; region <= R; region++) {
        int n, t; cin >> n >> t;

        vector<string> names(n);
        for (int i = 0; i < n; i++) cin >> names[i];

        vector<int> cnt(n, 0);
        int invalid = 0;

        for (int i = 0; i < t; i++) {
            string str; cin >> str;

            int xCount = 0;
            int pos = -1;

            for (int j = 0; j < (int)str.size(); j++) {
                char c = str[j];
                if (c == 'X' || c == 'x') {
                    xCount++;
                    pos = j;
                }
            }

            if (xCount == 1 && 0 <= pos && pos < n) cnt[pos]++;
            else invalid++;
        }

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0); // Assign increasing values starting from 1

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (cnt[a] != cnt[b]) return cnt[a] > cnt[b];
            return a < b;
        });

        cout << "Region # " << region << ":\n";
        cout << fixed << setprecision(2);

        for (int k = 0; k < n; k++) {
            int i = idx[k];
            long double pct = round2((long double)cnt[i] * 100.0L / (long double)t);
            cout << names[i] << " " << (double)pct << "%\n";
        }

        long double invPct = round2((long double)invalid * 100.0L / (long double)t);
        cout << "Invalid " << (double)invPct << "%\n";

        if (region != R) cout << "\n";
    }

    return 0;
}