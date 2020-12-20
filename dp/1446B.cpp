#include <bits/stdc++.h>
using namespace std;

int max(int a,int b,int c){return max(a,max(b,c));}
int dp[5010][5010][2];

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  string s,t;
  cin >> n >> m;
  cin >> s >> t;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      for(int k=0;k<=1;k++){
        if(!i or !j){
          dp[i][j][k] = 0;
          continue;
        }
        int ans = 0;
        if(k){
          int opt1=0,opt2=0,opt3=0;
          if(s[i-1] == t[j-1])
            opt1 = 2 + dp[i-1][j-1][k];
          opt2 = -1 + dp[i-1][j][k];
          opt3 = -1 + dp[i][j-1][k];
          ans = max(opt1,opt2,opt3);
        }else{
          int opt1=0,opt2=0,opt3=0;
          if(s[i-1] == t[j-1])
            opt1 = 2 + dp[i-1][j-1][1];
          opt2 = dp[i-1][j][k];
          opt3 = dp[i][j-1][k];
          ans = max(opt1,opt2,opt3);
        }
        dp[i][j][k] = ans;
      }
    }
  }
  cout << dp[n][m][0] << "\n";
}
