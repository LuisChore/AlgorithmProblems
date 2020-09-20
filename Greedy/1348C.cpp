#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int cases,n,k;
  cin >> cases;
  while(cases--){
    cin >> n >> k;
    cin >> s;
    sort(s.begin(),s.end());
    if(k == 1){
      cout << s << "\n";
      continue;
    }

    char curr = '-',first = s[0];
    int  different = 0,frec_first = 0;
    for(int i=0;i<s.size();i++){
      if(s[i] == first)
        frec_first++;
      if(s[i] != curr){
        different++;
        curr = s[i];
      }
    }

    if(s[0] != s[k-1]){
      cout << s[k-1] << "\n";
      continue;
    }

    if((different == 2 && frec_first == k) || different == 1){
      int ceil = (n + k - 1) / k;
      ceil--;
      cout << s[0];
      for(int i=0;i<ceil;i++)
        cout << s[k];
      cout << "\n";
      continue;
    }

    cout << s[0];
    for(int i=k;i<n;i++)
      cout << s[i];
    cout << "\n";

  }
  return 0;
}
