#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
lli n,st[400010];
void construct_st(int l=0,int r = n-1,int i = 0){
  if(l == r){
    st[i] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  construct_st(l,mid,i*2 + 1);
  construct_st(mid + 1,r,i*2 + 2);
  st[i] = 0;
}

lli sum(int s,int e,int l=0,int r = n-1,int i = 0){
  if(e<l || r<s)
    return 0;
  if(s<=l && r<=e)
    return st[i];
  int mid = (l + r) >> 1;
  lli L = sum(s,e,l,mid,i*2+1);
  lli R = sum(s,e,mid + 1,r,i*2+2);
  return L + R;
}

void update(int pos,lli val,int l = 0, int r = n-1,int i = 0){
  if(pos<l || r<pos)
    return;
  if(l == r){
    st[i] += val;
    return;
  }
  int mid = (l + r) >> 1;
  update(pos,val,l,mid,i*2+1);
  update(pos,val,mid+1,r,i*2+2);
  st[i] = st[i*2+1] + st[i*2+2];
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int k,m;
  cin >> m >> k;
  n = m + 1;
  vector<int> a(m);
  for(int i=0;i<m;i++)
    cin >> a[i];
  vector<lli> temp(n,1);
  for(int j=2;j<=k+1;j++){
    construct_st();
    for(int i=m-1;i>=0;i--){
      lli val = a[i];
      lli s = (val<m) ? sum(val + 1,m) : 0;
      update(val,temp[val]);
      temp[val] = s;
    }
  }
  lli ans = 0;
  for(int i=1;i<=m;i++){
    ans += temp[i];
  }
  cout << ans << "\n";
  return 0;
}
