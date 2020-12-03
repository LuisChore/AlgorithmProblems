#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B) {
  set<string> S;
  for(auto &s: B){
    reverse(s.begin(),s.end());
    S.insert(s);
  }

  vector<bool> dp(A.size() + 1, false);
  dp[0] = true;
  for(int i=1;i<=A.size();i++){
    string t = "";
    bool ans = false;
    for(int j=i;j>=max(1,i-19);j--){
      t+=A[j - 1];
      if(S.find(t) != S.end()){
        ans = ans || dp[j-1];
      }
    }
    dp[i] = ans;
  }
  return dp[A.size()];
}


int main(){
  string A = "myinterviewtrainer";
  vector<string> B = {"trainer", "my", "interview"};
  cout << wordBreak(A,B) << "\n";
  return 0;
}
