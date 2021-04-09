#include <iostream>
#include <vector>

using namespace std;

typedef long long lli;

bool is_possible(vector<int> &A,int B,lli mid){
  lli sum = 0,b = 1;
  for(int i=0;i<A.size();i++){
    if(sum + A[i] <= mid){
      sum += A[i];
    }else if(A[i] > mid){
      return false;
    }else{
      sum = A[i];
      b++;
    }
  }
  return b <= B;
}

int books(vector<int> &A, int B) {
  lli n = A.size();
  lli low = 0,high = n * 100000;
  if(B > n)
    return -1;
  lli ans = high;
  while(low<=high){
    lli mid = (low + high)>>1LL;
    bool ok = is_possible(A,B,mid);
    if(ok){
      ans = mid;
      high = mid - 1;
    }else{
      low = mid + 1;
    }
  }
  return ans;
}


int main(){
  vector<int>  A = {5, 17, 100, 11};
  int B = 4;
  cout << books(A,B) << "\n";
  return 0;
}
