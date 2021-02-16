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

vector<vector<int>> dp;
vector<int> a;
vector<int> gr;
int n;


vector<int> next_greater(vector<int> &v){
  vector<int> g(v.size(),v.size());
  stack<int> St;
  for(int i=1;i<v.size();i++){
    while(St.size() && v[St.top()] < v[i]){
      g[St.top()] = i;
      St.pop();
    }
    St.push(i);
  }
  return g;
}
bool f(int i,int j){
  if(i == n || j == n)
    return true;
  if(dp[i][j] != -1)
    return dp[i][j];

  int index = i + j + 1;
  int next = gr[index];
  int diff = next - index;
  bool opt1 = (i + diff <=n ) ? f(i + diff,j) : false;
  bool opt2 = (j + diff <=n ) ? f(i,j + diff) : false;
  return dp[i][j] = opt1 || opt2;
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    cin >> n;
    dp.assign(n+1,vector<int>(n+1,-1));
    a.assign(2*n+1,0);
    for(int i=1;i<=2*n;i++){
      cin >> a[i];
    }

    gr = next_greater(a);
    
    bool ans = f(0,0);
    if(ans){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }
  return 0;
}
