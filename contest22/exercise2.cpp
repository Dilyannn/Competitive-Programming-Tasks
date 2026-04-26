#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= x; j++) {
            for (int face = 1; face <= m && face <= j; face++) {
                dp[i][j] += dp[i - 1][j - face];
            }
        }
    }

    cout << "\nTotal number of ways is: " << dp[n][x] << endl;
    return 0;
}
