#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli inf = 1e18;
const lli inf_int = 1e9;

const int MOD = 1e9 + 7;

vector<lli> fact,inv;


lli a[200010];
int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  int cases;
  cin >> cases;
  lli n = 200000;
  lli k = 2,m = 3;
  while(cases--){
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    sort(a,a+n);
    lli ans = 0;
    for(int i=0;i<n;i++){
      lli max_value = a[i] + k;
      int low = i + 1,high = n-1,value = i;
      while(low<=high){
        int mid = (low + high)>>1;
        if(a[mid] <= max_value){
          value = mid;
          low = mid + 1;
        }else{
          high = mid - 1;
        }
      }

      int N = value - i;
      int K = m - 1;
      if(N>=K){
        if(N&1){
          lli aux = (N-1)/2LL * N;
          ans += aux;
        }else{
          lli aux = N/2LL  * (N-1);
          ans += aux;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
