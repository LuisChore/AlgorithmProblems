#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    int n,m,a,b;;
    cin >> n >> m >> a >> b;
    vector<int> v(m);
    for(int i=0;i<m;i++){
      cin >> v[i];
    }
    sort(v.begin(),v.end());
    int total = min(m,abs(a-b)-1);
    int maxi_time = (a<b) ? b - 2 : n - b - 1;
    int low = 0,high = total, ans = 0;
    while(low<=high){
      int mid = (low + high)>>1;
      int max_t = 0;
      for(int i=0,j=mid-1;j>=0;i++,j--){
        int ti = i + v[j];
        max_t = max(max_t,ti);
      }
      if(max_t <= maxi_time){
        ans = mid;
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
