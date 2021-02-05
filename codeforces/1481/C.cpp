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
    int n,m;
    cin >> n >> m;
    vector<int> Map(n+1,0);
    vector<int> a(n),b(n),c(m);
    vector<deque<int>> Color(n+2,deque<int>());
    vector<int> Ans(m,-1);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    for(int i=0;i<n;i++){
      cin >> b[i];
      Map[b[i]]++;
    }
    for(int i=0;i<m;i++){
      cin >> c[i];
      if(Map[c[i]])
        Color[c[i]].push_back(i);
      else
        Color[n+1].push_back(i);
    }
    bool ok = true;
    // check the bad ones
    for(int i=0;i<n;i++){
      if(a[i] == b[i])
        continue;
      int value = b[i];
      if(Color[value].size() == 0){
        ok = false;
        break;
      }
      int large = Color[value].back(),sum = 0;
      while(Color[n+1].size() && Color[n+1][0]<large){
        int index = Color[n+1][0];
        Ans[index] = i;
        Color[n+1].pop_front();
      }
      Ans[large] = i;
      Color[value].pop_back();
    }
    if(!ok){
      cout << "NO\n";
      continue;
    }

    for(int i=0;i<n;i++){
      if(a[i] != b[i])
        continue;
      int value = b[i];
      if(Color[value].size() == 0){
        continue;
      }

      int large = Color[value].back();
      while(Color[n+1].size() && Color[n+1][0]<large){
        int index = Color[n+1][0];
        Ans[index] = i;
        Color[n+1].pop_front();
      }
      Ans[large] = i;
      Color[value].pop_back();
    }
    if(Color[n+1].size()){
      cout << "NO\n";
      continue;
    }

    for(int i=0;i<n;i++){
      int value = b[i];
      if(Color[value].size() == 0){
        continue;
      }

      while(Color[value].size()){
        int index = Color[value][0];
        Ans[index] = i;
        Color[value].pop_front();
      }
    }

    cout << "Yes\n";
    for(int i=0;i<m;i++){
      cout << Ans[i] + 1 << " ";
    }cout << "\n";

  }
  return 0;
}
