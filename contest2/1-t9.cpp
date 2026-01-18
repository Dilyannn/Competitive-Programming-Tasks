#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int t9Solve(char c) {
    if (c >= 'A' && c <= 'C') return 2;
    if (c >= 'D' && c <= 'F') return 3;
    if (c >= 'G' && c <= 'I') return 4;
    if (c >= 'J' && c <= 'L') return 5;
    if (c >= 'M' && c <= 'O') return 6;
    if (c >= 'P' && c <= 'S') return 7;
    if (c >= 'T' && c <= 'V') return 8;
    return 9; 
}

char resW[105][105], resT9[105][105];
int clicks[105];       

void processWord(int cur[], int len, int M) {
    if (len == 0) return;

    char codeCh[105];
    for (int i = 0; i < len; i++) codeCh[i] = char('0' + cur[i]);
    codeCh[len] = '\0'; // 0 char

    for (int i = 0; i < M; i++) {
        if (strcmp(codeCh, resT9[i]) == 0) {
            cout << resW[i];
            return;
        }
    }

    for (int i = 0; i < len; i++) cout << "*";
}

int main() {
    int testCases; cin >> testCases;

    while (testCases--) {
        int nextRows; cin >> nextRows;

        for (int i = 0; i < nextRows; i++) cin >> resW[i];

        for (int i = 0; i < nextRows; i++) {
            int L = strlen(resW[i]);
            for (int j = 0; j < L; j++)
                resT9[i][j] = char('0' + t9Solve(resW[i][j]));
            resT9[i][L] = '\0';
        }

        int clicksCnt; cin >> clicksCnt;

        for (int i = 0; i < clicksCnt; i++) cin >> clicks[i];

        int cur[105], currSz = 0, isFirstWord = true;

        for (int i = 0; i < clicksCnt; i++) {
            if (clicks[i] == 1) {
                if (!isFirstWord) cout << " ";
                isFirstWord = false;

                processWord(cur, currSz, nextRows);

                currSz = 0;
            }
            else {
                cur[currSz++] = clicks[i];
            }
        }
        if (!isFirstWord) cout << " ";
        
        processWord(cur, currSz, nextRows);
        cout << endl;
    }
    
    return 0;
}