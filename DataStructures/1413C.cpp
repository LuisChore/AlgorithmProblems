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
  if(l<=s && e<=r)
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
  
  vector<int> S(6);
  for(int i=0;i<6;i++){
    cin >> S[i];
  }
  sort(S.begin(),S.end());
  reverse(S.begin(),S.end());
  cin >> n;
  vector<pair<int,int>> v;
  vector<deque<int>> tuples(n);
  for(int i=0;i<n;i++){
    lli aux;
    cin >> aux;
    for(int j=0;j<6;j++){
      lli diff = aux - S[j];
      tuples[i].push_back(diff);
      v.push_back({diff,i});
    }
    a[i] = tuples[i].front();
    tuples[i].pop_front();
  }
  construct_st();


  sort(v.begin(),v.end());
  lli ans = inf;
  for(int i=0;i<v.size();i++){
    lli m = v[i].first;
    int index = v[i].second;
    lli M = max_st(0,n-1);
    ans = min(ans,M-m);
    if(tuples[index].size()){
      lli new_value = tuples[index].front();
      tuples[index].pop_front();
      update(index,new_value);
    }else{
      break;
    }
  }

  cout << ans << "\n";
  return 0;
}
