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
    bool yes = false;
    for(int i=0;i<n;i++){
      cin >> a[0];
      cin >> a[1];
      cin >> a[2];
      cin >> a[3];
      if(a[1] == a[2]){
        yes = true;
      }
    }
    if(yes && k%2 == 0){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }
  return 0;
}
