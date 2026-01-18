#include <iostream>
using namespace std;

const int MAX_SZ = 100000;
bool isPrimeF[MAX_SZ + 1];

void solve() {
  for (int i = 0; i <= MAX_SZ; i++) {
    isPrimeF[i] = true;
  }
  isPrimeF[0] = isPrimeF[1] = false;

  for (int i = 2; i * i <= MAX_SZ; i++) {
    if (isPrimeF[i]) {
      for (int j = i * i; j <= MAX_SZ; j += i) {
        isPrimeF[j] = false;
      }
    }
  }
}

int main() {
  solve();

  int a, b, n;
  while (cin >> a >> b >> n) {
    int counter = 0;
    for (int k = 0; k < n; k++) {
      int x = a * k + b;
      if (isPrimeF[x]) {
        ++counter;
      }
    }
    cout << counter << endl;
  }

  return 0;
}
