#include <iostream>
using namespace std;

int main() {
    int price, paid;
    int test = 1;
    while (cin >> price >> paid) {
        if (price == 0 && paid == 0) break;

        int change = paid - price;
        int notes5 = change % 5;
        int notes10 = ((change - notes5) % 10 == 0) ? 0 : 1;
        int coins1 = (change - notes5 - 5 * notes10) / 10;
        cout << "Case " << test++ << ": " << change
             << " = " << coins1 << " * 10 + " << notes10 << " * 5 + "
             << notes5 << " * 1" << endl;
    }
    return 0;
}
