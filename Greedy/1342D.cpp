#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long lli;
const lli inf = 1e18;
const int inf_int = 1e9;

typedef tree<
lli,
null_type,//mapped key
less<lli>,//comp
rb_tree_tag,
tree_order_statistics_node_update
>ordered_set;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin >> n >> k;
  vector<int> v(n);
  vector<int> w(k+1);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  for(int i=0;i<k;i++){
    cin >> w[i+1];
  }
  vector<vector<int>> ans;
  set<pair<int,int>> Set;
  for(auto &vi: v){
    int value = w[vi];
    set<pair<int,int>> :: iterator it = Set.upper_bound({-value,inf_int});
    if(it != Set.end()){
      pair<int,int> temp = *it;
      Set.erase(temp);
      temp.first--;
      ans[temp.second].push_back(vi);
      Set.insert(temp);
    }else{
      ans.push_back(vector<int>());
      ans.back().push_back(vi);
      Set.insert({-1,ans.size()-1});
    }
  }

  cout << ans.size() << "\n";
  for(auto &ti: ans){
    cout << ti.size();
    for(auto &aux: ti){
      cout << " " << aux;
    }
    cout << "\n";
  }
  return 0;
}
