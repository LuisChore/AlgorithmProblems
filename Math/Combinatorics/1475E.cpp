#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

lli mod = 1e9 + 7;
lli pow(lli a,lli e){
  lli ans = 1;
  while(e){
    if(e&1){
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    e>>=1;
  }
  return ans;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  vector<lli> fact(1010);
  vector<lli> inv(1010);
  fact[0] = 1;
  for(lli i=1;i<=1000;i++)
    fact[i] = i * fact[i-1] % mod;

  inv[1000] = pow(fact[1000],mod - 2);
  for(lli i=999;i>=0;i--)
    inv[i] = inv[i+1] * (i + 1) % mod;

  cin >> cases;
  while(cases--){
    lli n,k;
    cin >> n >> k;
    vector<lli> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int left = 0,right = 0,value = a[k-1];
    for(int i=0;i<n;i++){
      if(a[i] == value && i<k){
        right++;
      }else if(a[i] == value){
        left++;
      }
    }
    lli ans = (fact[left + right] * inv[left]  % mod ) * inv[right]  % mod;
    cout << ans << "\n";
  }
  return 0;
}
