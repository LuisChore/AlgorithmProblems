#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli mod = 1e9 + 7;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  if(s.size() == 1){
    cout << 0 << "\n";
    return 0;
  }
  vector<lli> LR;
  LR.push_back(s[0] - '0');
  for(int i=1;i<s.size();i++){
    LR.push_back(s[i] - '0');
    lli temp = (LR[i-1] * 10LL % mod  + LR.back() ) % mod;
    LR[i] = temp;
  }

  for(int i=1;i<s.size();i++){
    LR[i]  = (LR[i] + LR[i-1]) % mod;
  }

  lli ans = LR[s.size() - 2],value = 0;

  lli pot10 = 1;
  for(int i=s.size()-1;i>=1;i--){
    lli temp = (s[i] - '0') * pot10 % mod;
    value = (value + temp);
    ans = (ans + value) % mod;
    pot10 = pot10 * 10LL % mod;
    if(i>1){
      lli aux = (LR[i-2] * pot10 % mod + (i-1) * value % mod) % mod;
      ans = (ans + aux) % mod;
    }
  }

  cout << ans << "\n";
  return 0;
}
