#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

const int inf_int = 1e9;
const lli inf = 1e18;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  lli n,k;
  vector<int> v;
  map<int,pair<int,lli>> Map;
  cin >> n >> k;
  v.assign(n,0);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  sort(v.begin(),v.end());
  lli ans = inf;
  for(int i=0;i<n;i++){
    int t = 0;
    while(true){
      Map[v[i]].first++;
      Map[v[i]].second += t;
      t++;
      if(Map[v[i]].first == k){
        ans = min(ans,Map[v[i]].second);
      }
      if(v[i] == 0)
        break;
      else
        v[i] /= 2;
    }
  }
  cout << ans << "\n";
  return 0;
}
