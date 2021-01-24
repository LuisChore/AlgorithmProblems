#include <bits/stdc++.h>
using namespace std;
int b[2000010];
void pre_kmp(string &s){
  int n = s.size();
  int i=0,j=-1;
  b[0] = j;
  while(i<n){
    while(j>=0 && s[i] != s[j])j = b[j];
      i++;
      j++;
      b[i] = j;
  }
}

int kmp(string &s,string &t){
  int n = s.size();
  int m = t.size();
  int j = 0,i = max(0,n - m);
  while(i<n){
    while(j>=0 && s[i] != t[j])j = b[j];
      i++;
      j++;
      if( i == n){
        return j;
      }
      if( j == m){
        j = b[j];
      }
  }
}


int main(){
  int n;
  cin >> n;
  vector<string> S(n);
  for(int i=0;i<n;i++){
    cin >> S[i];
  }
  int index = 1;
  string ans = S[0];
  while(index < n){
    pre_kmp(S[index]);
    int aux = kmp(ans,S[index]);
    for(int i=aux;i<S[index].size();i++){
      ans += S[index][i];
    }
    index++;
  }
  cout << ans << "\n";
  return 0;
}
