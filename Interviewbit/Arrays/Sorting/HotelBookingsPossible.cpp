#include <bits/stdc++.h>
using namespace std;
// find-the-point-where-maximum-intervals-overlap/
bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
  sort(arrive.begin(),arrive.end());
  sort(depart.begin(),depart.end());
  int curr = 0,maxi = 0;
  int j = 0; // depart
  for(int i=0;i<arrive.size();i++){
    while(j < depart.size() && depart[j] <= arrive[i]){
      j++;
      curr--;
    }
    curr++;
    maxi = max(maxi,curr);
  }
  return K >= maxi;
}

int main(){
  vector<int> A = {1, 3, 5};
  vector<int> B = {2, 6, 8};
  int C = 1;
  cout << hotel(A,B,C) << "\n";
  return 0;
}
