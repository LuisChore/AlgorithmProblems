#include <bits/stdc++.h>
using namespace std;
typedef long long lli;


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  lli n,p;
  cin >> n >> p;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  lli m = max(a.back() - n + 1,1LL);
  lli M = a.back();
  vector<lli> t;
  for(int i=m;i<=M + n;i++){
    t.push_back(upper_bound(a.begin(),a.end(),i) - a.begin());
  }

  vector<lli> ans;
  for(int i = m,j = 0;i<=M;i++,j++){
    bool ok = true;
    for(int k=0;k<n;k++){
      lli aux = t[j + k] - k;
      if(aux % p == 0){
        ok = false;
        break;
      }
    }
    if(ok){
      ans.push_back(i);
    }
  }

  cout << ans.size() << "\n";
  for(int i=0;i<ans.size();i++){
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
