#include <bits/stdc++.h>
using namespace std;



int firstMissingPositive(vector<int> &A) {
  int n = A.size();
  for(int i=0;i<n;i++){
    if(1 <= A[i] && A[i]<=n){
      while(A[i] != (i + 1)){
        int u = A[i];
        int v = A[u - 1];
        if(v == u)
          break; // special case
        A[u - 1] = u;
        A[i] = v;
        if(A[i] <= 0 || A[i]>n)
          break;
      }
    }
  }

  int ans = n + 1;
  for(int i=0;i<n;i++){
    if(A[i] != (i + 1)) {
      ans = i + 1;
      break;
    }
  }
  return ans;
}

int main(){
  vector<int> A = {1,2,0};
  cout << firstMissingPositive(A) << "\n";
  vector<int> B = {1,1,1};
  cout << firstMissingPositive(B) << "\n";
  return 0;
}
