#include <bits/stdc++.h>
using namespace std;



bool can(vector<int> &A,vector<int> &B,int mid){
  int j = 0,n = A.size();
  bool ok = true;
  for(int i=mid;i<n;i++){
    if(A[i] < B[j]){
      ok = false;
      break;
    }
    j++;
  }
  j = B.size() - 1;
  for(int i=mid-1;i>=0;i--){
    if(A[i] > B[j]){
      ok = false;
      break;
    }
    j--;
  }
  return ok;
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    int n;
    cin >> n;
    vector<int> A(n),B(n);
    int j = 1,k = 0;
    for(int i=0;i<n;i++){
      cin >> A[i];
      while(j<=2*n && j<A[i]){
        B[k++] = j++;
      }
      j = A[i] + 1;
    }
    while(j<=2*n){
      B[k++] = j++;
    }
    int ceil = 0;
    for(int i=0;i<n;i++){
      if(B[i] > A[i]){
        ceil++;
      }
    }

    //lower
    int lower_bound = ceil;
    int low = 0,high = ceil;
    while(low<=high){
      int mid = (low + high) >> 1;
      if(can(A,B,mid)){
        lower_bound = mid;
        high = mid - 1;
      }else{
        low = mid + 1;
      }
    }

    int upper_bound = lower_bound;
    low = lower_bound;
    high = n;
    while(low<=high){
      int mid = (low + high) >> 1;
      if(can(A,B,mid)){
        upper_bound = mid;
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }
    cout << upper_bound - lower_bound + 1<< "\n";


  }
  return 0;
}
