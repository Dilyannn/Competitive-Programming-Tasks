#include <iostream>
using namespace std;

int price[11];
int minPriceForKm[1005];
int km, maxRangeEver;

int taxiRecursion(const int remainderP) {
    if (remainderP == 0) return 0;
    if (minPriceForKm[remainderP] != -1) {
        return minPriceForKm[remainderP];
    }

    int best = maxRangeEver;
    for (int i = 1; i <= 10; i++) {
        if (i <= remainderP) {
            int candidate = taxiRecursion(remainderP - i) + price[i];
            if (candidate < best) best = candidate;
        }
    }
    return minPriceForKm[remainderP] = best;
}

int main() {
    while (true) {
        if (!(cin >> price[1])) break;
        for (int i = 2; i <= 10; i++) {
            if (!(cin >> price[i])) {
                return 0;
            }
        }
        if (!(cin >> km)) break;

        int mx = price[1];
        for (int i = 2; i <= 10; i++) {
            if (price[i] > mx) {
                mx = price[i];
            }
        }
        maxRangeEver = km * mx + 1;

        for (int i = 0; i <= 1000; i++) {
            minPriceForKm[i] = -1;
        }

        const int totalCost = taxiRecursion(km);
        cout << totalCost << endl;
    }

    return 0;
}
