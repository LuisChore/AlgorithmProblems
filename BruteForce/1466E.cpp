#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

const lli mod = 1e9 + 7;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    lli n;
    cin >> n;
    vector<lli> v(n);
    vector<lli> on(60);
    vector<lli> off(60);
    for(int i=0;i<n;i++){
      cin >> v[i];
      for(lli b = 0;b<60;b++){
        if(v[i] & (1LL<<b)){
          on[b]++;
        }else{
          off[b]++;
        }
      }
    }
    lli ans = 0;
    for(int j=0;j<n;j++){
      lli temp = v[j] % mod;
      lli andj = n * temp % mod;
      for(lli b=0;b<60;b++){
        lli temp2 = (1LL<<b) % mod;
        if(v[j] & (1LL<<b)){
          lli x = off[b];
          andj = (andj - x * temp2 % mod) % mod;
        }
      }
      if(andj<0)
        andj += mod;

      lli orj = n * temp % mod;
      for(lli b=0;b<60;b++){
        lli temp2 = (1LL<<b) % mod;
        if(!(v[j] & (1LL<<b))){
          lli x = on[b];
          orj = (orj + x * temp2 % mod) % mod;
        }
      }
      ans = (ans + andj*orj%mod)%mod;
    }

    cout << ans << "\n";
  }
}
