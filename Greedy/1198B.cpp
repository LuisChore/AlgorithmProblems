#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const int inf_int = 1e9;
const lli inf = 1e18;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,q;
  lli curr_max = -1;
  vector<lli> v;
  vector<lli> base;
  vector<pair<int,lli>> Q;
  cin >> n;
  v.assign(n + 1,-1);
  base.assign(n + 1,-1);
  for(int i=1;i<=n;i++){
    cin >> base[i];
  }
  cin >> q;
  for(int i=0;i<q;i++){
    int t;
    lli p,x;
    cin >> t;
    if(t == 1){
      cin >> p >> x;
      Q.push_back({p,x});
    }else{
      cin >> x;
      Q.push_back({-1,x});
    }
  }
  reverse(Q.begin(),Q.end());
  for(auto &qi: Q){
    if(qi.first == -1){
      curr_max = max(curr_max,qi.second);
    }else{
      if(v[qi.first] == -1){
        v[qi.first] = max(qi.second,curr_max);
      }
    }
  }

  for(int i=1;i<=n;i++){
    if(v[i] != -1){
      cout << v[i] << " ";
    }else{
      cout << max(curr_max,base[i]) << " ";
    }
  }
  cout << "\n";
  return 0;
}
