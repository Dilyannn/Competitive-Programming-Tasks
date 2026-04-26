#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int zero;
        cin >> zero;

        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int type;
        int typeCnt = 0;

        while (cin >> type && type != 3 && typeCnt < 300000) {
            typeCnt++;

            if (type == 1) {
                int position, x;
                cin >> position >> x;

                arr[position - 1] = x;
            }
            else if (type == 2) {
                int v1, v2;
                cin >> v1 >> v2;

                auto start = arr.begin() + v1 - 1;
                auto end = arr.begin() + v2;

                auto minIt = min_element(start, end);
                auto maxIt = max_element(start, end);

                int minn = *minIt;
                int maxx = *maxIt;

                int minCnt = count(start, end, minn);
                int maxCnt = count(start, end, maxx);

                cout << minn << ' ' << minCnt << ' ' << maxx << ' ' << maxCnt << '\n';
            }
        }
    }

    return 0;
}