#include <bits/stdc++.h>
using namespace std;


vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
  vector<long long> acum(nums.size(),0);
  long long sum = 0;
  int n = nums.size();
  for(int i=0;i<n;i++){
    sum += nums[i];
    if(i>=k-1){
      acum[i-k+1] = sum;
      sum -= nums[i-k+1];
    }
  }

  vector<int> MAX1K(n,0);
  MAX1K[k-1] = 0;
  for(int i=k;i<n;i++){
    if(acum[MAX1K[i-1]] < acum[i-k+1]){
      MAX1K[i] = i - k + 1;
    }else{
      MAX1K[i] = MAX1K[i-1];
    }
  }



  vector<pair<int,int>> MAX2K(n);
  MAX2K[2*k - 1] = {0,k};
  for(int i=2*k;i<n;i++){
    int temp = acum[i-k+1] + acum[MAX1K[i-k]];
    if(temp > acum[MAX2K[i-1].first] + acum[MAX2K[i-1].second]){
      MAX2K[i] = {MAX1K[i-k],i-k+1};
    }else{
      MAX2K[i] = MAX2K[i-1];
    }
  }



  vector<int> ans = {0,k,2*k};
  for(int i=3*k;i<n;i++){
    int temp = acum[i- k + 1] + acum[MAX2K[i-k].first] + acum[MAX2K[i-k].second];
    if(temp > acum[ans[0]] + acum[ans[1]] + acum[ans[2]]){
      ans[0] = MAX2K[i-k].first;
      ans[1] = MAX2K[i-k].second;
      ans[2] = i - k + 1;
    }
  }
  return ans;
}

int main(){
  vector<int> v = {1,2,1,2,6,7,5,1};
  vector<int> ans = maxSumOfThreeSubarrays(v,2);
  cout << ans[0] << " ";
  cout << ans[1] << " ";
  cout << ans[2] << " ";
  return 0;
}
