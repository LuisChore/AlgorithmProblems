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

vector<tuple<int,int,int>> books;
vector<int> acum,a,MapSum,dp;
map<int,int> Map;
int n,m;

int f(int index){
  if(index == n)
    return 0;
  if(dp[index] != -1)
    return dp[index];
  int opt1 = acum[index];
  int opt2 = f(index + 1);
  int opt3 = 0;
  int low = 0,high = books.size()-1;
  while(low<=high){
    int mid = (low + high)>>1;
    if(get<0>(books[mid]) > index){
      high = mid - 1;
    }else if(get<0>(books[mid]) < index){
      low = mid + 1;
    }else{
      opt3 = f(get<1>(books[mid]) + 1) + get<2>(books[mid]);
      break;
    }
  }
  int ans = max(opt1,max(opt2,opt3));
  return dp[index] = ans;
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  a.assign(n+1,0);
  dp.assign(n+1,-1);
  MapSum.assign(n+1,0);
  acum.assign(n+1,0);
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(Map.count(a[i]) == 0)
      Map[a[i]] = m++;
  }
  books.assign(m,{inf_int,-inf_int,0});
  for(int i=0;i<n;i++){
    int index = Map[a[i]];
    get<0>(books[index]) = min(get<0>(books[index]),i);
    get<1>(books[index]) = max(get<1>(books[index]),i);
    get<2>(books[index]) = get<2>(books[index]) + 1;
  }
  for(int i=n-1;i>=0;i--){
    MapSum[a[i]]++;
    acum[i] = max(acum[i+1],MapSum[a[i]]);
  }

  sort(books.begin(),books.end());
  int ans = f(0);
  cout << n - ans << "\n";
  return 0;
}
