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

vector<string> S;
vector<vector<int>> dp;
vector<string> digits = {
  "1110111",
  "0010010",
  "1011101",
  "1011011",
  "0111010",
  "1101011",
  "1101111",
  "1010010",
  "1111111",
  "1111011",
};
int change_cost(string &s,string &t){
  int ans  = 0;
  for(int i=0;i<s.size();i++){
    if(s[i] == '1' && t[i] == '0')
      ans++;
    if(s[i] == '0' && t[i] == '1')
      return -1;
  }
  return ans;
}
bool f(int index,int k){
  if(index == S.size())
    return (k == 0);
  if(dp[index][k] != -1)
    return dp[index][k];
  bool ans = false;
  for(int i=9;i>=0;i--){
    int can = change_cost(digits[i],S[index]);
    if(can != -1 && k>=can){
      ans = ans || f(index + 1,k-can);
    }
  }
  return dp[index][k] = ans;
}

void construct(int index,int k){
  if(index == S.size())
    return;
  for(int i=9;i>=0;i--){
    int can = change_cost(digits[i],S[index]);
    if(can != -1 && k>=can){
      if(f(index + 1,k-can)){
          cout << i;
          construct(index + 1, k-can);
          break;
      }
    }
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin >> n >> k;
  S.assign(n,"");
  for(int i=0;i<n;i++)
    cin >> S[i];
  dp.assign(n,vector<int>(k+1,-1));
  bool ans = f(0,k);
  if(!ans){
    cout << -1 << "\n";
    return 0;
  }
  construct(0,k);
  cout << "\n";
  return 0;
}
