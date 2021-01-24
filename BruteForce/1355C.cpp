#include <bits/stdc++.h>
using namespace std;
typedef long long lli;


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  lli a,b,c,d,ans = 0;
  cin >> a >> b >> c >> d;
  vector<int> Map(b+c+2,0);
  for(lli i = a;i<=b;i++){
    lli tmp = i + c;
    Map[tmp]++;
    tmp = i + b -1;
    Map[tmp]--;
  }
  for(int i= b + c;i>=0;i--){
    Map[i] += Map[i+1];
  }
  for(lli i = max(a + b,c + 1);i<=b + c;i++){
    lli r = min(d,i-1);
    if(r>=c){
      ans += (r-c+1) * Map[i];
    }
  }
  cout << ans << "\n";
  return 0;
}
