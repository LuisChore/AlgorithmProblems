#include <iostream>
#include <vector>
using namespace std;

int minDistance(string A, string B) {
  int n = A.size(),m = B.size();
  vector<vector<int>> dp(n+1,vector<int>(m+1,0));
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(i == 0 || j == 0){
        dp[i][j] = i + j;
        continue;
      }
      if(A[i-1] == B[j-1]){
        dp[i][j] = dp[i-1][j-1];
      }else{
        int ins = dp[i][j-1];
        int del = dp[i-1][j];
        int rep = dp[i-1][j-1];
        int mini = min(ins,min(del,rep));
        dp[i][j] = 1 + mini;
      }
    }
  }
  return dp[n][m];
}

int main(){
  string A = "abad";
  string B = "abac";
  cout << minDistance(A,B) << "\n";
}
