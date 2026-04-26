#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    int arrIdx;
    int elemIdx;
    bool operator>(const Node& other) const {
        return val > other.val;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int K, N;
        cin >> K >> N;

        vector<vector<int>> arrays(K, vector<int>(N));
        for (int i = 0; i < K; i++)
            for (int j = 0; j < N; j++)
                cin >> arrays[i][j];

        priority_queue<Node, vector<Node>, greater<Node>> minHeap;
        for (int i = 0; i < K; i++)
            minHeap.push({arrays[i][0], i, 0});

        bool first = true;
        while (!minHeap.empty()) {
            Node cur = minHeap.top();
            minHeap.pop();

            if (!first) cout << ' ';
            cout << cur.val;
            first = false;

            if (cur.elemIdx + 1 < N)
                minHeap.push({arrays[cur.arrIdx][cur.elemIdx + 1], cur.arrIdx, cur.elemIdx + 1});
        }
        cout << '\n';
    }

    return 0;
}
