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
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    int temp = 0,ok = 1;
    for(int i=1;i<=k;i++){
      for(int j=0;j<n;j++){
        if(j == n-1){
          ok = false;
          break;
        }
        if(a[j] >= a[j+1])
          continue;
        else{
          temp = j + 1;
          a[j]++;
          break;
        }
      }
      if(!ok)
        break;
    }

    if(!ok){
      cout << -1 << "\n";
    }else{
      cout << temp << "\n";
    }
  }
  return 0;
}
