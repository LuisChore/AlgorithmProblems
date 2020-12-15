#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli inf = 1e18;
const lli inf_int = 1e9;

int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    int n;
    cin >> n;
    if(n>45){
      cout << -1 << "\n";
      continue;
    }
    lli ans = inf;
    for(int i=0;i<(1<<9);i++){
      lli sum = 0;
      for(int j=0;j<9;j++){
        if(i&(1<<j)){
          sum += (j+1);
        }
      }
      if(sum != n){
        continue;
      }
      lli value = 0;
      for(int j=0;j<9;j++){
        if(i&(1<<j)){
          value = value * 10 + (j + 1);
        }
      }
      ans = min(ans,value);
    }
    if(ans == inf){
      cout << -1 << "\n";
    }else{
      cout << ans << "\n";
    }
  }
  return 0;
}
