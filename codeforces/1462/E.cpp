#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli inf = 1e18;
const lli inf_int = 1e9;

const int MOD = 1e9 + 7;

vector<lli> fact,inv;

lli exp_bin(lli b,lli e,lli mod = MOD){
  lli r = 1LL;
  while(e){
    if(e&1){
      r = r * b % mod;
    }
    e>>=1LL;
    b = (b * b) % mod;
  }
  return r;
}


void factorials(int n){
  fact.assign(n+1,1);
  for(lli i=2;i<=n;i++){
    fact[i] = (i * fact[i-1]) % MOD;
  }
}


lli inv_mod(int n){
  return exp_bin(fact[n],MOD - 2);
}


void inverses(int n){
  inv.assign(n+1,1);
  inv[n] = inv_mod(n);
  for(lli i=n-1;i>=0;i--){
    inv[i] = (inv[i+1] * (i+1LL)) % MOD;
  }
}


lli nck(int n,int k){
  return (fact[n] * inv[n-k] % MOD) * inv[k] % MOD;
}


lli a[200010];
int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  int cases;
  cin >> cases;
  lli n = 200000;
  factorials(n);
  inverses(n);
  while(cases--){
    lli m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    sort(a,a+n);
    lli ans = 0;
    for(int i=0;i<n;i++){
      lli max_value = a[i] + k;
      int low = i + 1,high = n-1,value = i;
      while(low<=high){
        int mid = (low + high)>>1;
        if(a[mid] <= max_value){
          value = mid;
          low = mid + 1;
        }else{
          high = mid - 1;
        }
      }

      int N = value - i;
      int K = m - 1;
      if(N>=K)
        ans = (ans + nck(N,K))% MOD;
    }
    cout << ans << "\n";
  }
  return 0;
}
