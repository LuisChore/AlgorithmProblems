#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  lli n,cases;
  cin >> cases;
  while(cases--){
    cin >> n;
    lli low = 1,high = n,ans = 0;
    while(low<=high){
      lli mid = (low + high)>>1;
      lli value = 2*mid + 1;
      lli aux = (value * value -1) / 2;
      if(aux < n){
        ans = value / 2;
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
