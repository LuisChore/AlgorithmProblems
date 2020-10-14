#include <bits/stdc++.h>
using namespace std;

const int inf_int = 1e9;
vector<int> v;

bool is_palindrome(vector<int> &v){
  int l = 0, r = v.size() - 1;
  while(l < r){
    if(v[l] != v[r]){
      return false;
    }
    l++;
    r--;
  }
  return true;
}
int f(int l,int r,int ki,int K){
  if(ki > K)
    return inf_int;
  if(l>=r)
    return 0;

  if(v[l] == v[r]){
    return f(l+1,r-1,ki,K);
  }else{
    int a = f(l+1,r,ki + 1,K) + 1;
    int b = f(l,r-1,ki + 1,K) + 1;
    return min(a,b);
  }
}
int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  int cases,c = 1;
  cin >> cases;
  while(cases--){
    int n,k;
    cin >> n >> k;
    v.assign(n,0);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    if(is_palindrome(v)){
      cout << "Case " << c++ << ": Too easy" << "\n";
      continue;
    }
    int value = f(0,n-1,0,k);
    if(value >= inf_int){
      cout << "Case " << c++ << ": Too difficult\n";
    }else{
      cout << "Case " << c++ << ": " << value << "\n";
    }

  }
  return 0;
}

/*
4
4 2
10 20 30 10
4 2
10 20 30 40
4 3
10 20 30 40
3 0
10 20 10
*/
