#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int safePosition(vector<vector<int>>& matrix, int r, int c) {
  int n = matrix.size();
  int i, j;

  for (i = 0; i < r; i++) if (matrix[i][c]) return 0; //cu
  for (i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) if (matrix[i][j]) return 0; //uld
  for (i = r - 1, j = c + 1; j < n && i >= 0; i--, j++) if (matrix[i][j]) return 0; // urd

  return 1;
}

void queensGenerator(int row, vector<vector<int>>& matrix, vector<vector<int>>& result) {
  int n = matrix.size(); // 8
  if(row == n) {
    vector<int> ans;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(matrix[i][j]){
          ans.push_back(j + 1);
        }
      }
    }
    result.push_back(ans);
    return;
  }

  for(int i = 0; i < n; i++){

    if(safePosition(matrix, row, i)){
      matrix[row][i] = 1;
      queensGenerator(row + 1, matrix, result);
      matrix[row][i] = 0;
    }
  }
}

int main() {
  int chessBoard[8][8] = { 0 };

  int queensCounter = 1;
  vector<map<int, int>> queens;

  while (queensCounter <= 8) {
    for (int i = 0; i < queensCounter; i++) {
      for (int j = 0; j < queensCounter; j++) {
        chessBoard[i][j] = 0;
      }
    }
  }

  return 0;
}