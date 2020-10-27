#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    long long n,m,k;
    cin >> n >> m >> k;
    vector<long long> v(n+1,0);
    int ans = 0;
    for(int i=1;i<=n;i++){
      cin >> v[i];
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
      if(v[i] > m)
        break;
      if(i<k){
        v[i] += v[i-1];
        if(v[i] <= m){
          ans = i;
        }
      }else if(m >= (v[i] + v[i-k])){
        v[i] += v[i-k];
        ans = i;
      }else{
        v[i] += v[i-k];
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
