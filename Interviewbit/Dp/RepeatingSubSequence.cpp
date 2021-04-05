#include <bits/stdc++.h>
using namespace std;

int anytwo(string A) {
  const int inf = 10000;
  int n = A.size();
  vector<int> F(n,inf);
  vector<int> L(n,-1);
  map<char,int> Alpha;
  for(int i=0;i<n;i++){
    if(Alpha.count(A[i]) == 0){
      Alpha[A[i]] = i;
    }else{
      F[Alpha[A[i]]] = i;
      Alpha[A[i]] = i;
    }
  }
  for(int i=1;i<n;i++){
    F[i] = min(F[i-1],F[i]);
  }

  Alpha.clear();
  for(int i=n-1;i>=0;i--){
    if(Alpha.count(A[i]) == 0)
      Alpha[A[i]] = i;
    else{
      L[i] = Alpha[A[i]];
    }
  }

  for(int i=n-2;i>=0;i--){
    L[i] = max(L[i+1],L[i]);
  }

  for(int i=0;i<n-1;i++){
    if(F[i] < L[i+1])
      return 1;
  }
  return 0;
}
int main(){
  cout << anytwo("OKyi") << "\n";
  cout << anytwo("abba") << "\n";
  cout << anytwo("aaa") << "\n";
  cout << anytwo("abb") << "\n";
  return 0;
}
