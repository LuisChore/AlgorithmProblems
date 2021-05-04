#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void create_subsets(vector<vector<int>> &ans,vector<int> &A,
  vector<int> &curr,bool in = true,int index = 0){
  if(in)
    ans.push_back(curr);

  if(index == A.size())
    return;

  curr.push_back(A[index]);
  create_subsets(ans,A,curr,true,index + 1);
  curr.pop_back();
  create_subsets(ans,A,curr,false,index + 1);
}

vector<vector<int> > subsets(vector<int> &A) {
  sort(A.begin(),A.end());
  vector<vector<int>> ans;
  vector<int> curr;
  create_subsets(ans,A,curr);
  return ans;
}

int main(){
  vector<int> A = {};
  vector<vector<int>> ans = subsets(A);
  for(auto &v: ans){
    for(auto &x: v){
      cout << x << ",";
    }
    cout << "\n";
  }
}
