#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const int inf_int = 1e9;
const lli inf = 1e18;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  string s;
  cin >> cases;
  while(cases--){
    cin >> s;
    int n = s.size();
    string ans  = "";
    int even = s.size(),odd = s.size();
    for(int i=0;i<s.size();i++){
        if(even == n && (s[i] - '0')%2 == 0)
          even = i;
        if(odd == n && (s[i] - '0')&1)
          odd = i;
    }

    while(even<n && odd < n){
      if(s[even] < s[odd]){
        ans += s[even];
        even++;
        while(even<n && (s[even]-'0')&1)
          even++;
      }else{
        ans += s[odd];
        odd++;
        while(odd<n && (s[odd]-'0')%2 == 0)
          odd++;
      }
    }

    while(even<n){
      if((s[even]-'0')&1)
        even++;
      else
        ans += s[even++];
    }
    while(odd<n){
      if((s[odd]-'0')%2 == 0)
        odd++;
      else
        ans += s[odd++];
    }
    cout << ans << "\n";
  }
}
