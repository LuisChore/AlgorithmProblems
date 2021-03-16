#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
lli n;
vector<lli> st;
vector<lli> lazy,x;

void construct_st(int l = 1,int r = n,int i = 0){
  if(l == r){
    st[i] = 0;
    lazy[i] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  construct_st(l,mid,i*2+1);
  construct_st(mid+1,r,i*2+2);
  st[i] = 0;
  lazy[i] = 0;
}

void update(int s,int e,int val,int l=1,int r = n,int i = 0){
  if(lazy[i]){
    st[i] += (r-l + 1) * lazy[i];
    if(l != r){
      lazy[i*2+1] += lazy[i];
      lazy[i*2+2] += lazy[i];
    }
    lazy[i] = 0;
  }
  if(l>e || s>r)
    return;
  if(s<=l && r<=e){
    st[i] += (r-l+1) * val;
    if(l != r){
      lazy[i*2+1] += val;
      lazy[i*2+2] += val;
    }
    return;
  }
  int mid = (l + r) >> 1;
  update(s,e,val,l,mid,i*2+1);
  update(s,e,val,mid + 1,r,i*2+2);
  st[i] = st[i*2+1] + st[i*2+2];
}


int sum(int s,int e,int l=1,int r = n,int i = 0){
  if(lazy[i]){
    st[i] += (r-l + 1) * lazy[i];
    if(l != r){
      lazy[i*2+1] += lazy[i];
      lazy[i*2+2] += lazy[i];
    }
    lazy[i] = 0;
  }
  if(l>e || s>r)
    return 0;
  if(s<=l && r<=e){
    return st[i];
  }
  int mid = (l + r) >> 1;
  int L = sum(s,e,l,mid,i*2+1);
  int R = sum(s,e,mid + 1,r,i*2+2);
  return L + R;
}



int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    cin >> n;
    st.assign(4*n,0);
    lazy.assign(4*n,0);
    x.assign(n+1,0);
    for(int i=1;i<=n;i++){
      cin >> x[i];
    }
    lli ans = 0;
    for(int i=1;i<=n;i++){
      if(x[i] == 1)
        continue;
      construct_st();
      ans += (x[i] - 1);
      // cout << i << " " << x[i] << "\n";
      if(i+2 <=n)
        update(i+2,min(n,i+x[i]),1);
      //
      // for(int j=i+2;j<=n;j++)
      //   cout << sum(j,j) << ",";
      // cout << "\n";
      for(int j=i+2;j<=n;j++){
        lli value = sum(j,j);
        if(value == 0)
          continue;
        int l = j + x[j] - value + 1;
        l = max(j+1,l);
        int r = min(n,j+x[j]);
        if(l<=r)
          update(l,r,1);
        int d = j + x[j] - value + 1;
        if(j>=d)
          update(j+1,j+1,j-d+1);
        x[j] = max(x[j]-value,1LL);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
