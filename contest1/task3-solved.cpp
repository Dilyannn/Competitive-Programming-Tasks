#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int aXL, aYT, aXR, aYB;
    int bXL, bYT, bXR, bYB;

    while (cin >> aXL >> aYT >> aXR >> aYB >> bXL >> bYT >> bXR >> bYB) {

        int widthA  = max(0, aXR - aXL);
        int heightA = max(0, aYT - aYB);

        int widthB  = max(0, bXR - bXL);
        int heightB = max(0, bYT - bYB);

        int areaA = widthA * heightA;
        int areaB = widthB * heightB;

        int widthBetween  = max(0, min(aXR, bXR) - max(aXL, bXL));
        int HeightBetween = max(0, min(aYT,   bYT) - max(aYB, bYB));
        int intersectionArea = widthBetween * HeightBetween;

        int sumOfAreas = areaA + areaB;
        int unionArea  = sumOfAreas - intersectionArea;

        cout << sumOfAreas << ' ' << unionArea << ' ' << intersectionArea << endl;
               }
    return 0;
}
