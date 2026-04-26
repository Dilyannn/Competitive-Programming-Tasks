#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const vector<long long>& nums, const vector<long long>& given) {
    vector<long long> sums;

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            sums.push_back(nums[i] + nums[j]);
        }
    }

    sort(sums.begin(), sums.end());

    return sums == given;
}

bool solveCase(vector<long long> s, vector<long long>& answer) {
    sort(s.begin(), s.end());

    long long total = 0;

    for (int i = 0; i < 10; i++) {
        total += s[i];
    }

    if (total % 4 != 0) {
        return false;
    }

    long long sumOfNumbers = total / 4;

    long long x1x2 = s[0];
    long long x1x3 = s[1];

    for (int i = 2; i < 10; i++) {
        long long x2x3 = s[i];

        long long value = x1x2 + x1x3 - x2x3;

        if (value % 2 != 0) {
            continue;
        }

        long long x1 = value / 2;
        long long x2 = x1x2 - x1;
        long long x3 = x1x3 - x1;

        if (x1 <= 0 || x2 <= 0 || x3 <= 0) {
            continue;
        }

        if (!(x1 <= x2 && x2 <= x3)) {
            continue;
        }

        long long x4x5 = sumOfNumbers - x1 - x2 - x3;

        for (int j = 0; j < 10; j++) {
            long long x1x4 = s[j];

            long long x4 = x1x4 - x1;
            long long x5 = x4x5 - x4;

            if (x4 <= 0 || x5 <= 0) {
                continue;
            }

            if (!(x3 <= x4 && x4 <= x5)) {
                continue;
            }

            vector<long long> nums;

            nums.push_back(x1);
            nums.push_back(x2);
            nums.push_back(x3);
            nums.push_back(x4);
            nums.push_back(x5);

            if (check(nums, s)) {
                answer = nums;
                reverse(answer.begin(), answer.end());
                return true;
            }
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        vector<long long> s(10);

        for (int i = 0; i < 10; i++) {
            cin >> s[i];
        }

        vector<long long> answer;

        if (solveCase(s, answer)) {
            for (int i = 0; i < 5; i++) {
                if (i > 0) {
                    cout << " ";
                }

                cout << answer[i];
            }

            cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}