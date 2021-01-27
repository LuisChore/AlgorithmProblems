#include <bits/stdc++.h>
using namespace std;

const int inf_int = 1e9;
string s;
int n;
int dp[200010][4][4];

int f(int index,int flag, int start){
  if(index ==  n){
    if(start == 0 && (flag == 0 || flag == 2))
      return inf_int;
    if(start == 1 && flag == 0)
      return inf_int;
    if(start == 3 && (flag == 1 || flag == 3))
      return inf_int;
    if(start == 2 && flag == 3)
      return inf_int;
    return 0;
  }

  if(dp[index][flag][start] != -1)
    return dp[index][flag][start];

  if(flag == 0)
    return dp[index][flag][start] = (s[index] != 'R') + f(index + 1,1,start);

  if(flag == 3)
    return dp[index][flag][start] = (s[index] != 'L') + f(index + 1,2,start);

  if(flag == 1){
    int opt1 = (s[index] != 'R') + f(index + 1, 3, start);
    int opt2 = (s[index] != 'L') + f(index + 1, 2, start);
    return dp[index][flag][start] = min(opt1,opt2);
  }

  if(flag == 2){
    int opt1 = (s[index] != 'R') + f(index + 1, 1, start);
    int opt2 = (s[index] != 'L') + f(index + 1, 0, start);
    return dp[index][flag][start] = min(opt1,opt2);
  }

}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    cin >> n >> s;
    for(int i=0;i<=n;i++){
      for(int j=0;j<4;j++){
        for(int k = 0; k<4;k++){
          dp[i][j][k] = -1;
        }
      }
    }
    int zero = (s[0] != 'L') + (s[1] != 'L') + f(2,0,0);
    int one = (s[0] != 'L') + (s[1] != 'R') + f(2,1,1);
    int two = (s[0] != 'R') + (s[1] != 'L') + f(2,2,2);
    int three = (s[0] != 'R') + (s[1] != 'R') + f(2,3,3);
    int ans = min(zero,one);
    ans = min(ans,two);
    ans = min(ans,three);
    cout << ans << "\n";
  }
}
