#include <bits/stdc++.h>
using namespace std;

int seats(string A) {
  int count = 0;
  for(int i=0;i<A.size();i++){
    if(A[i] == 'x')
      count++;
  }
  if(count <= 1)
    return 0;
  int index = 0,median = (count >> 1) + (count & 1);
  int sum = 0;
  for(int i=0;i<A.size();i++){
    if(A[i] == 'x'){
      sum++;
      if(median == sum){
        index = i;
        break;
      }
    }
  }
  int ans = 0,found = 0;
  sum = 0;
  for(int i=index + 1;i<A.size();i++){
    if(A[i] == 'x'){
      ans += sum - found;
      found++;
    }
    sum++;
  }
  found = 0;
  sum = 0;
  for(int i=index -1;i>=0;i--){
    if(A[i] == 'x'){
      ans += sum - found;
      found++;
    }
    sum++;
  }
  return ans;
}

int main(){
  string A = "x.xx";
  cout << seats(A) << "\n";
  return 0;
}
