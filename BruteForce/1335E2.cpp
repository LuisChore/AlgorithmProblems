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
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    vector<int> L(201,0);
    vector<vector<int>> R(201,vector<int>(n+1,0));
    int best_ans = 0;
    for(int i=n-1;i>=0;i--){
      R[a[i]][i] = 1;
      for(int j=1;j<=200;j++){
        R[j][i] += R[j][i+1];
        best_ans = max(best_ans,R[j][i]);
      }
    }

    for(int i=0;i<n;i++){
      L[a[i]] += 1;
      int sum = L[a[i]];
      int low = 0,high = n-1,ans = low;
      while(low<=high){
        int mid = (low + high)>>1;
        if(R[a[i]][mid] >= sum){
          ans = mid;
          low = mid + 1;
        }else{
          high = mid - 1;
        }
      }
      if(ans <= i)
        continue;
      int l = i+1,r = ans-1;
      int best = 0;
      for(int j=1;j<=200;j++){
        int aux = R[j][l] - R[j][r+1];
        best = max(best,aux);
      }
      best_ans = max(best_ans,2*sum + best);
    }
    cout << best_ans << "\n";
  }
  return 0;
}
