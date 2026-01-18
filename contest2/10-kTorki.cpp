#include <iostream>
#include <vector>
using namespace std;

int main() {
    int testCases; cin >> testCases;

    while (testCases--) {
        int n, k; cin >> n >> k;

        vector<long long> dp(k + 1), next(k + 1);
        dp[0] = 1;                    

        for (int i = 0; i < n; i++) {
            int cnt; cin >> cnt;
            vector<int> v(cnt);

            for (int j = 0; j < cnt; j++) cin >> v[j];
            for (int s = 0; s <= k; s++) next[s] = 0;

            for (int s = 0; s <= k; s++) {
                if (!dp[s]) continue;  
                for (int el : v) {
                    if (s + el <= k) {
                      next[s + el] += dp[s];
                    }
                }
            }
            dp.swap(next);
        }
        cout << dp[k] << endl;
    }

    return 0;
}
