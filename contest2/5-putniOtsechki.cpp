#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int testCase;
    if (!(cin >> testCase)) return 0;

    while (testCase--) {
        int n, m; cin >> n >> m;

        vector<vector<int>> citizen(n + 1);
        vector<vector<char>> po(n + 1, vector<char>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if (!po[x][y]) {
                po[x][y] = po[y][x] = 1;
                citizen[x].push_back(y);
                citizen[y].push_back(x);
            }
        }

        int qCalls;
        cin >> qCalls;
        string result;

        for (int i = 0; i < qCalls; i++) {
            int type, u, v;
            cin >> type >> u >> v;

            if (type == 1) {
                vector<char> vector(n + 1, 0);
                queue<int> queue;
                queue.push(u);
                vector[u] = 1;
                bool isOk = false;

                while (!queue.empty()) {
                    int x = queue.front();
                    queue.pop();
                    if (x == v) {
                        isOk = true;
                        break;
                    }
                    for (int y : citizen[x]) {
                        if (po[x][y] && !vector[y]) {
                            vector[y] = 1;
                            queue.push(y);
                        }
                    }
                }

                result.push_back(isOk ? '1' : '0');
            } else if (type == 2) {
                if (!po[u][v]) {
                    po[u][v] = po[v][u] = 1;
                    citizen[u].push_back(v);
                    citizen[v].push_back(u);
                }
            } else if (type == 3) {
                po[u][v] = po[v][u] = 0;
            }
        }

        cout << result << endl;
    }

    return 0;
}