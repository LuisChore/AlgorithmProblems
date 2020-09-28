#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a,string &b){
  return (a + b) > (b + a);
}

string largestNumber(const vector<int> &A) {
  vector<string> S;
  for(int i=0;i<A.size();i++){
    S.push_back(to_string(A[i]));
  }
  sort(S.begin(),S.end(),cmp);
  if(S[0][0] == '0')
    return "0";
  string ans = "";
  for(auto &si: S){
    ans += si;
  }
  return ans;
}

int main(){
  vector<int> A = {3, 30, 34, 5, 9};
  cout << largestNumber(A) << "\n";
}
