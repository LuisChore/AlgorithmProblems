#include <vector>
#include <iostream>

using namespace std;
int candy(vector<int> &A) {
  vector<int> candies(A.size(),1);
  for(int i=1;i<A.size();i++){
    if(A[i] > A[i-1] && (i == A.size()-1 || A[i+1] >= A[i])){
      candies[i] = candies[i-1] + 1;
    }
  }
  for(int i = A.size()-2;i >= 0; i--){
    if(A[i] > A[i+1] && (i == 0 || A[i-1] >= A[i])){
      candies[i] = candies[i+1] + 1;
    }else if(i > 0 && A[i-1] < A[i] && A[i] > A[i+1]){
      candies[i] = max(candies[i-1],candies[i+1]) + 1;
    }
  }
  int ans = 0;
  for(auto &ci : candies){
    ans += ci;
  }
  return ans;
}

int main(){
  vector<int> A = {1,5,2,1};
  cout << candy(A) << "\n";
}
