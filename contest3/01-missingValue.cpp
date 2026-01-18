#include <bits/stdc++.h>
using namespace std;

int findMissing(vector<int>& a) {
  sort(a.begin(), a.end());

  for (int i = 0; i + 1 < static_cast<int>(a.size()); i++) {
    if (a[i + 1] - a[i] > 2) {
      return a[i] + 2;
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  while (cin >> n >> m) {
    vector<int> evenNum(n), oddNum(m);

    for (int i = 0; i < n; i++) cin >> evenNum[i];
    for (int i = 0; i < m; i++) cin >> oddNum[i];

    cout << findMissing(evenNum) << endl;
    cout << findMissing(oddNum) << endl;
  }

  return 0;
}