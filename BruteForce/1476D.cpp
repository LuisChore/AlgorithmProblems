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
    int n;
    string s;
    cin >> n >> s;
    vector<int> L(n,0);
    vector<int> R(n,0);
    // ->
    int acum = 1;
    R[n-1] = (s[n-1] == 'R') ? 1 : 0;
    for(int i=n-2;i>=0;i--){
      acum = (s[i] != s[i+1]) ? acum + 1 : 1;
      R[i] = (s[i] == 'L') ? 0 : acum;
    }

    // <-
    acum = 1;
    L[0] = (s[0] == 'L') ? 1: 0;
    for(int i=1;i<n;i++){
      acum = (s[i] != s[i-1]) ? acum + 1: 1;
      L[i] = (s[i] == 'R') ? 0 : acum;
    }
    cout << R[0] + 1;
    for(int i=1;i<n;i++){
      cout << " ";
      cout << R[i] + L[i-1] + 1;
    }
    
    cout << " " << L[n-1] + 1 << "\n";

  }
  return 0;
}
