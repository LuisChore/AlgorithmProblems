#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
lli n,m,k,cases;
string s,t;
lli a[200010];
vector<lli> v;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> cases;
  while(cases--){
    cin >> n >> k;
    if(n <= 2){
      cout << 1 << "\n";
    }else{
      n-=2;
      cout << 1 + (n + k - 1)/k << "\n";
    }
  }
  return 0;
}
