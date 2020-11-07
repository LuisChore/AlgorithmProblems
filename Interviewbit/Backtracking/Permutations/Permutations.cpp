#include <bits/stdc++.h>
using namespace std;

void permutations(vector<int> &A,vector<vector<int>> &sol, vector<int> &curr,int index = 0){
  if(index == A.size()){
    sol.push_back(curr);
    return;
  }
  for(int i=0;i<A.size();i++){
    if(curr[i] == -1){
      curr[i] = A[index];
      permutations(A,sol,curr,index + 1);
      curr[i] = -1;
    }
  }
}


vector<vector<int>> permute(vector<int> &A) {
  vector<int> curr_solution(A.size(),-1);
  vector<vector<int>> ans;
  permutations(A,ans,curr_solution);
  return ans;
}


int main(){
  vector<int> A = {1,2,3};
  vector<vector<int>> ans = permute(A);
  for(auto &v: ans){
    for(auto &x: v){
      cout << x << " ";
    }
    cout << "\n";
  }

}
