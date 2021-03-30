#include <iostream>
#include <vector>
using namespace std;
void sortColors(vector<int> &A) {
  int two = A.size()-1,zero = 0;
  for(int i=0;i<A.size();i++){
    if(A[i] == 0){
      swap(A[i],A[zero]);
      zero++;
    }else if(A[i] == 2 && two>i){
      swap(A[i],A[two]);
      two--;
      if(two >= i)
        i--;
    }
  }
}

int main(){
  vector<int> A = {2, 2, 2, 0, 1, 0};
  sortColors(A);
  for(auto &Ai:A)
    cout << Ai << " ";
  return 0;
}
