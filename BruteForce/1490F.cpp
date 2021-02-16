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
    vector<lli> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    sort(a.begin(),a.end());
    int sum = 1;
    vector<lli> v;
    for(int i=1;i<n;i++){
      if(a[i] != a[i-1]){
        v.push_back(sum);
        sum = 1;
      }else{
        sum++;
      }
    }
    v.push_back(sum);
    sort(v.begin(),v.end());
    vector<lli> L(v.size()+1,0);
    vector<lli> R(v.size()+1,0);
    for(int i=0;i<v.size();i++){
      L[i] = v[i];
      if(i)
        L[i] += L[i-1];
    }
    for(int i= v.size()-1;i>=0;i--){
      R[i] = v[i];
      R[i] += R[i+1];
    }
    lli ans = n;
    for(int i=0;i<v.size();i++){
      int j = i;
      lli val = v[i];
      while((j+1)<v.size() && v[j+1] == v[i])
        j++;
      lli sumR = R[j+1];
      lli sumL = (i ? L[i-1] : 0 );
      lli needR = sumR - (v.size()-j-1) * val;
      ans = min(ans,sumL + needR);
      i = j;
    }
    cout << ans << "\n";
  }
  return 0;
}
