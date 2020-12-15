#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli inf = 1e18;
const lli inf_int = 1e9;

int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    int n;
    string s;
    cin >> n;
    cin >> s;
    if(n<4){
      cout << "NO\n";
      continue;
    }
    if(s.substr(0,1) == "2" && s.substr(n-3,3) == "020"){
      cout << "YES\n";
      continue;
    }

    if(s.substr(0,2) == "20" && s.substr(n-2,2) == "20"){
      cout << "YES\n";
      continue;
    }

    if(s.substr(0,3) == "202" && s.substr(n-1,1) == "0"){
      cout << "YES\n";
      continue;
    }

    if(s.substr(0,4) == "2020" || s.substr(n-4,4) == "2020"){
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";

  }
  return 0;
}
