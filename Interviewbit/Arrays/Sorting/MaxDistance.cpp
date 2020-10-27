#include <bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &A) {
  vector<int> v;
  int ans = 0;
  for(int i=0;i<A.size();i++){
    if(!v.size()){
      v.push_back(i);
      continue;
    }
    if(A[v.back()] > A[i] ){
      v.push_back(i);
      continue;
    }

    int low = 0, high = v.size() - 1, possible = i;
    while(low <= high){
      int mid = (low + high) >> 1;
      if(A[v[mid]] <= A[i]){
        possible = v[mid];
        high = mid - 1;
      }else{
        low = mid + 1;
      }
    }
    ans = max(ans,i-possible);

  }
  return ans;
}

int main(){
  vector<int>  A = {3, 5, 4, 2};
  cout << maximumGap(A) << "\n";
}
