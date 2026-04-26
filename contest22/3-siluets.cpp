#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;

    while (cin >> N >> M) {
        vector<int> A(N), B(M);

        long long sumA = 0;
        long long sumB = 0;

        int maxA = 0;
        int maxB = 0;

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            sumA += A[i];
            maxA = max(maxA, A[i]);
        }

        for (int i = 0; i < M; i++) {
            cin >> B[i];
            sumB += B[i];
            maxB = max(maxB, B[i]);
        }

        if (maxA != maxB) {
            cout << "No Solution." << '\n';
            continue;
        }

        int maxH = maxA;

        vector<int> countA(maxH + 1, 0);
        vector<int> countB(maxH + 1, 0);

        for (int i = 0; i < N; i++) {
            countA[A[i]]++;
        }

        for (int i = 0; i < M; i++) {
            countB[B[i]]++;
        }

        long long saved = 0;

        for (int h = 1; h <= maxH; h++) {
            saved += 1LL * h * min(countA[h], countB[h]);
        }

        long long minVolume = sumA + sumB - saved;

        sort(B.begin(), B.end());

        vector<long long> prefix(M + 1, 0);

        for (int i = 0; i < M; i++) {
            prefix[i + 1] = prefix[i] + B[i];
        }

        long long maxVolume = 0;

        for (int i = 0; i < N; i++) {
            int x = A[i];

            int pos = upper_bound(B.begin(), B.end(), x) - B.begin();

            long long smallerOrEqual = prefix[pos];
            long long bigger = 1LL * (M - pos) * x;

            maxVolume += smallerOrEqual + bigger;
        }

        cout << minVolume << " " << maxVolume << '\n';
    }

    return 0;
}