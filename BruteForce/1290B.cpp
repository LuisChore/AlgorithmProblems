#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long lli;
const lli inf = 1e18;

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
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> v(26,vector<int>(n,0));
  for(int i=0;i<n;i++){
    int index = s[i] - 'a';
    v[index][i] = 1;
    if(i)
      for(int j=0;j<26;j++){
        v[j][i] += v[j][i-1];
      }
  }
  int q;
  cin >> q;
  while(q--){
    int l,r;
    cin >> l >> r;
    l--;
    r--;
    if(l == r){
      cout << "Yes\n";
      continue;
    }
    int diff = 0;
    vector<int> f(26);
    for(int j=0;j<26;j++){
      int index = j;
      int sum = v[index][r];
      if(l)
        sum -= v[index][l-1];
      f[j] = sum;
      if(f[j])
        diff++;
    }

    int li = s[l] - 'a';
    int ri = s[r] - 'a';

    if(li != ri || diff>2){
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }
  }
  return 0;
}
