#include <iostream>
#include <vector>

using namespace std;

int cntBits(vector<int> &A) {
  long long mod = 1e9 + 7;
  long long ans = 0;
  vector<long long> bits_frec(32,0);
  for(auto &x: A){
    long long temp = x;
    for(long long i = 0;i<32;i++){
      if(temp & (1<<i)){
        bits_frec[i]++;
      }
    }
  }

  for(auto &x: bits_frec){
    long long aux = x * (A.size() - x) * 2 % mod;
    ans = (ans + aux) % mod;

  }
  return ans;
}

int main(){
  vector<int> A = {1,3,5};
  cout << cntBits(A) << "\n";
}
