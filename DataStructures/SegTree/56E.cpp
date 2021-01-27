#include <bits/stdc++.h>

using namespace std;
typedef long long lli;
const lli inf = 1e18;
lli maxst[400010];
lli a[100010],n;

void construct_st(int l=0,int r = n-1,int i = 0){
  if(l == r){
    maxst[i] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  construct_st(l,mid,i*2+1);
  construct_st(mid + 1,r,i*2+2);
  maxst[i] = max(maxst[i*2 + 1],maxst[i*2 + 2]);
}

lli max_st(int s,int e,int l=0,int r = n-1,int i = 0){
  if(e<l || s>r)
    return - inf;
  if(s<=l && r<=e)
    return maxst[i];
  int mid = (l + r) >> 1;
  lli L = max_st(s,e,l,mid,i*2+1);
  lli R = max_st(s,e,mid+1,r,i*2+2);
  return max(L,R);
}

void update(int pos,lli value,int l = 0,int r = n-1,int i = 0){
  if(pos<l || pos>r)
    return;
  if(l == r){
    maxst[i] = value;
    return;
  }
  int mid = (l + r) >> 1;
  update(pos,value,l,mid,i*2+1);
  update(pos,value,mid + 1,r,i*2+2);
  maxst[i] = max(maxst[i*2 + 1],maxst[i*2 + 2]);
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<pair<lli,pair<lli,int>>> V(n);
  vector<int> Ans(n);
  for(int i=0;i<n;i++){
    cin >> V[i].first;
    cin >> V[i].second.first;
    V[i].second.second = i;
  }

  sort(V.begin(),V.end());
  update(n-1,n-1);
  a[n - 1] = n - 1;
  for(int i=n-2;i>=0;i--){
    lli xi = V[i].first;
    lli hi = V[i].second.first;
    int low = i,high = n - 1,ans = i;
    while(low<=high){
      int mid = (low + high) >> 1;
      if(V[mid].first < xi + hi){
        ans = mid;
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }

    int maxi = max_st(i,ans);
    maxi = max(maxi,i);
    update(i,maxi);
    a[i] = maxi;
  }
  for(int i=0;i<n;i++){
    a[i] = a[i] - i + 1;
    Ans[V[i].second.second] = a[i];
  }
  for(int i=0;i<n;i++){
    cout << Ans[i] << " ";
  }
  return 0;
}
