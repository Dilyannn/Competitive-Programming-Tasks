#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isEqual(vector<vector<char>> A, vector<vector<char>> B, int n){
    bool isCorrect = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j] != B[i][j]){
                isCorrect = false;
            }
        }
    }
    return isCorrect;
}

void printRotate(vector<vector<char>> A,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void rotate(vector<vector<char>>& A, int n){
    vector<vector<char>> res(n, vector<char>(n));
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[n - j - 1][i] = A[i][j];
        }
    }
    
    A = res;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        bool equalA = false;
        cin>>n;
        vector<vector<char>> A;

        for (int i = 0; i < n; i++) {
            vector<char> row;
            string r;
            cin>>r;

            for (int j = 0; j < n; j++) {
                row.push_back(r[j]);
            }

            A.push_back(row);
        }
        
        vector<vector<char>> B;

        for (int i = 0; i < n; i++) {
            vector<char> row;
            string r;
            cin>>r;

            for (int j = 0; j < n; j++) {
                row.push_back(r[j]);
            }

            B.push_back(row);
        }
        
        
        if(isEqual(A,B,n)){
            cout<<"YES"<<endl;
        }
        else{
            for(int i=0;i<3 && equalA != true;i++){
                rotate(A,n);
                if(isEqual(A,B,n)){
                    equalA=true;
                }
            }
            if(equalA){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
        
    }
    return 0;
}