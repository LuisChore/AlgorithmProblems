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

vector<int> acum;
vector<vector<int>> dp;
int n,k;
string s;
int get(int l,int r){
  if(l>r)
    return 0;
  int x = acum[r];
  if(l)
    x -= acum[l-1];
  return x;
}
int f(int index,int on){
  if(index == n)
    return 0;
  if(dp[index][on] != -1)
    return dp[index][on];
  if(on){
    int other = get(index,n-1);
    int ans = s[index] == '0';
    int next = min(n-1,index + k-1);
    ans += get(index+1,next);
    return dp[index][on] = min(f(next + 1,on) + ans,other);
  }else{
    int opt1 = f(index,true);
    int opt2 = f(index + 1,on) + (s[index] == '1');
    return dp[index][on] = min(opt1,opt2);
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    cin >> n >> k;
    cin >> s;
    acum.assign(n,0);
    dp.assign(n,vector<int>(2,-1));
    for(int i=0;i<n;i++){
      if(s[i] == '1')
        acum[i] = 1;
      if(i)
        acum[i] += acum[i-1];
    }
    cout << f(0,0) << "\n";
  }
  return 0;
}
