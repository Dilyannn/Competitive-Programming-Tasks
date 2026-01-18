#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

void transformToDecimal(const int n, const int *arr) {
    int *arr2 = new int[n];
    int counter = 0;
    for (int i = n - 1; i > 0; i--) {
        arr2[i] = pow(2, counter) * arr[i];
        counter++;
    }

    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    delete[] arr;
    delete[] arr2;
}

string transformToBinary(int n) {
    string binary;
    while (n > 0) {
        int bit = n % 2; // mod
        binary.push_back('0' + bit);
        n /= 2;
    }

    reverse(binary.begin(), binary.end());
    return binary;
}

int main() {
    int n;
    cin >> n;
    switch (n) {
        case n == 2:
            cout << "YES" << endl;
            break;
        case n == 10: cout << transformToBinary(n) << endl;
            break;
        default: cout << "Error" << endl;
            break;
    }
    string name;
    getline(cin, name);

    cout << transformToBinary(n) << endl;

    return 0;
}
