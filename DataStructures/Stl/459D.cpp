#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long lli;
const lli inf = 1e18;

typedef tree<
pair<int,int>,
null_type,//mapped key
less<pair<int,int>>,//comp
rb_tree_tag,
tree_order_statistics_node_update
>ordered_set;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  ordered_set S;
  unordered_map<int,int> MapR;
  unordered_map<int,int> MapL;
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    MapL[a[i]]++;
  }
  lli ans = 0;
  for(int i=n-1;i>=0;i--){
    pair<int,int> temp = {MapL[a[i]],0};
    ans += S.order_of_key(temp);
    MapL[a[i]]--;
    MapR[a[i]]++;
    S.insert({MapR[a[i]],i});
  }
  cout << ans << "\n";
  return 0;
}
