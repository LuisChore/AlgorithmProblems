#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  lli n,sum = 0,aux,ans = 0;
  cin >> n;
  map<long long,long long> Map;
  Map[0] = 0;
  lli best = -1;
  for(int i=0;i<n;i++){
    cin >> aux;
    sum += aux;
    if(Map.count(sum) != 0){
      best = max(best,Map[sum]);
    }
    ans += (best + 1);
    Map[sum] = i + 1;
  }
  ans = n * (n + 1LL) / 2LL - ans;
  cout << ans << "\n";
  return 0;
}
