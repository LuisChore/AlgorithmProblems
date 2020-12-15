#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli inf = 1e18;
const lli inf_int = 1e9;

lli a[5010];
int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    lli n,sum = 0;
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> a[i];
      sum +=a[i];
    }
    vector<lli> facts;
    for(lli i=1;i*i<=sum;i++){
      if(sum%i == 0){
        facts.push_back(i);
        lli temp = sum/i;
        if(temp != i)
          facts.push_back(temp);
      }
    }
    sort(facts.begin(),facts.end());
    int ans = n - 1;
    for(auto &x: facts){
      lli add = 0;
      int op = 0;
      bool ok = true;
      for(int i=0;i<n;i++){
        add += a[i];
        if(add>x){
          ok = false;
          break;
        }
        if(add == x){
          add = 0;
          continue;
        }
        op++;
      }
      if(ok == true){
        ans = op;
        break;
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
