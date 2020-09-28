#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
lli n,m,k,cases;
string s,t;
lli a[200010];
vector<lli> v;


lli root(lli n){
  lli low = 1, high = 1000000LL, ans = n;
  while(low<=high){
    lli mid = (low + high) >> 1LL;
    if(mid * mid <= n){
      ans = mid;
      low = mid  + 1;
    }else{
      high = mid - 1;
    }
  }
  return ans;
}

pair<lli,lli> f(lli n,lli a){
  if(a*a >= n){
    return {a,a};
  }else if( (a + 1LL)*a >= n){
    return {a+1,a};
  }else{
    return {a+1,a+1};
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> cases;
  while(cases--){
    cin >> n;
    if(n<=3){
      cout << n - 1 << "\n";
      continue;
    }
    pair<lli,lli> p = f(n,root(n));
    cout << p.first + p.second - 2<< "\n";
  }
  return 0;
}
