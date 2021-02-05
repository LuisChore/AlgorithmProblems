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
  int cases;
  cin >> cases;
  while(cases--){
    int x,y;
    string s;
    cin >> x >> y;
    cin >> s;
    int xi = 0,yi = 0;
    for(int i=0;i<s.size();i++){
      if(s[i] == 'U')yi++;
      if(s[i] == 'D')yi--;
      if(s[i] == 'R')xi++;
      if(s[i] == 'L')xi--;
    }

    int u = 0,d = 0,l = 0, r= 0;
    if(yi > y)
    u = yi - y;
    else
    d = y - yi;

    if(xi > x)
    r = xi - x;
    else
    l = x - xi;

    for(int i=0;i<s.size();i++){
      if(s[i] == 'U' && u)u--;
      if(s[i] == 'D' && d)d--;
      if(s[i] == 'R' && r)r--;
      if(s[i] == 'L' && l)l--;
    }
    if(d + u + l + r > 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
