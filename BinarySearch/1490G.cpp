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
    int n,q;
    cin >> n >> q;
    vector<lli> a(n+1);
    for(int i=1;i<=n;i++){
      cin >> a[i];
    }
    lli sum = 0;
    vector<pair<lli,int>> Acum;
    for(int i=1;i<=n;i++){
      sum += a[i];
      if(Acum.size() == 0 && sum > 0){
        Acum.push_back({sum,i});
        continue;
      }

      if(Acum.size() && sum > Acum.back().first){
        Acum.push_back({sum,i});
      }
    }
    bool limit = (sum > 0);

    while(q--){
      lli qi;
      cin >> qi;

      if(Acum.size() == 0){
        cout << -1 << "\n";
        continue;
      }

      // first
      if(qi <= Acum.back().first){
        int low = 0,high = Acum.size()-1,ans = high;
        while(low<=high){
          int mid = (low + high)>>1;
          if(Acum[mid].first >= qi){
            ans = mid;
            high = mid - 1;
          }else{
            low = mid + 1;
          }
        }
        cout << Acum[ans].second - 1<< "\n";
        continue;
      }

      if(!limit){
        cout << -1 << "\n";
        continue;
      }

      lli low = 0,high = 1000000000,ans = high;
      while(low<=high){
        lli mid = (low + high)>> 1;
        //lli aux = (mid * (mid + 1LL)) >> 1LL;
        lli value = Acum.back().first + sum * mid;
        if(value >= qi){
          ans = mid;
          high = mid - 1;
        }else{
          low = mid + 1;
        }
      }
      lli temp = ans;
      lli aux = ans;
      low = 0;
      high = Acum.size()-1;
      ans = high;
      while(low<=high){
        lli mid = (low + high)>>1;
        lli value = Acum[mid].first  + sum * aux;
        if(value >= qi){
          ans = mid;
          high = mid - 1;
        }else{
          low = mid + 1;
        }
      }
      cout << Acum[ans].second + temp*n - 1 << "\n";

    }
  }
  return 0;
}
