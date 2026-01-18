#include <iostream>
#include <map>
using namespace std;

int main() {
    int testCases; cin >> testCases;

    while (testCases--) {
        int nSegments; cin >> nSegments;

        map<int,int> diff;

        for (int i = 0; i < nSegments; i++) {
            int x, y;
            cin >> x >> y;
            diff[x] += 1;
            diff[y + 1] -= 1;
        }

        int current = 0, prev = 0, maxValueM = 0, points = 0;
        bool isfirst = true;

        for (auto it = diff.begin(); it != diff.end(); it++) {
            int res = it->first;

            if (!isfirst) {
                int length = res - prev;
                if (current > maxValueM) {
                    maxValueM = current;
                    points = length;
                } else if (current == maxValueM) {
                    points += length;
                }
            }

            current += it->second;
            prev = res;
            isfirst = false;
        }
        cout << maxValueM << " " << points << endl;
    }

    return 0;
}