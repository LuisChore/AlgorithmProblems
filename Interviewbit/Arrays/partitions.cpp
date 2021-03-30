#include <iostream>
#include <vector>
#include <map>

using namespace std;
int solve(int A, vector<int> &B) {
  vector<int> L(B.size(),0);
  long long sum = 0;
  for(auto &Bi: B){
    sum += Bi;
  }
  if(sum % 3)
    return 0;
  long long partial_sum = sum / 3;
  long long acum = 0,ans = 0;
  for(int i=B.size()-1;i>=0;i--){
    acum += B[i];
    L[i] += acum == partial_sum;
    if(i < B.size() - 1)
      L[i]+=L[i+1];
  }
  acum = 0;
  for(int i=0;i<B.size()-2;i++){
    acum += B[i];
    if(acum == partial_sum){
      ans += L[i+2];
    }
  }
  return ans;
}

int main(){
  vector<int> B = {0,0,0,0,0,0,0,0,0};
  cout << solve(5,B) << "\n";
}
