#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        long double C, sum = 0;
        cin >> C;
        int L;
        cin >> L;
        while(L--){
            long double w, l;
            cin >> w >> l;
            sum += (w * l) * C;
        }
        cout << fixed << setprecision(7) << sum << endl;
    }
    return 0;
}