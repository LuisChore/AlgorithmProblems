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

vector<vector<int>> adj;
vector<int> Val,v,Ans;
void dfs1(int u, int parent = -1){
  for(auto &v: adj[u]){
    if(v == parent)
      continue;
    dfs1(v,u);
    if(Val[v] > 0)
      Val[u] += Val[v];
  }
}

void dfs(int u,int parent = -1,int parent_value = 0){
  int temp = max(0,parent_value);
  for(auto &v: adj[u]){
    if(v == parent)
      continue;
    if(Val[v] > 0)
      temp += Val[v];
  }
  int aux = (v[u]) ? (1) : -1;
  temp += aux;
  Ans[u] = temp;
  for(auto &v: adj[u]){
    if(v == parent)
      continue;
    if(Val[v] > 0)
      temp -= Val[v];
    dfs(v,u,temp);
    if(Val[v] > 0)
      temp += Val[v];
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  adj.assign(n + 1,vector<int>());
  v.assign(n+1,0);
  Ans.assign(n+1,0);
  Val.assign(n+1,0);
  for(int i=1;i<=n;i++){
    cin >> v[i];
    if(v[i])
      Val[i] = 1;
    else
      Val[i] = -1;
  }

  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs1(1);
  dfs(1);
  for(int i=1;i<=n;i++){
    cout << Ans[i] << " ";
  }
  return 0;
}
