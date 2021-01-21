#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

lli a[200010],n;
lli st[800010];
lli lazy[800010];

void construct_st(int l=0,int r = n-1,int i = 0){
  if(l == r){
    st[i] = a[l];
    lazy[i] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  construct_st(l,mid,i*2+1);
  construct_st(mid + 1,r,i*2+2);
  lazy[i] = 0;
  st[i] = st[i*2+1] + st[i*2+2];
}

void update(int s,int e,int val,int l = 0,int r = n-1,int i = 0){
  if(lazy[i]){
    st[i] += (r-l+1) * lazy[i];
    if(l != r){
      lazy[i*2 + 1] += lazy[i];
      lazy[i*2 + 2] += lazy[i];
    }
    lazy[i] = 0;
  }
  if(e<l || s > r)
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
  update(s,e,val,l,mid,i*2 + 1);
  update(s,e,val,mid + 1, r, i*2+2);
  st[i] = st[i*2 + 1] + st[i*2 + 2];
}

lli sum(int s,int e,int l = 0,int r = n-1,int i = 0){
  if(lazy[i]){
    st[i] += (r-l+1) * lazy[i];
    if(l != r){
      lazy[i*2 + 1] += lazy[i];
      lazy[i*2 + 2] += lazy[i];
    }
    lazy[i] = 0;
  }
  if(e<l || s > r)
    return 0;
  if(s<=l && r<=e)
    return st[i];

  int mid = (l + r) >> 1;
  lli L = sum(s,e,l,mid,i*2 + 1);
  lli R = sum(s,e,mid + 1, r, i*2 + 2);
  return L + R;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> n;
  cin >> s;
  vector<deque<int>> V(26);
  for(int i=0;i<n;i++){
    int index = s[i] - 'a';
    a[i] = i;
    V[index].push_front(i);
  }
  construct_st();

  lli index = 0,ans = 0;
  for(int i=n-1;i>=0;i--){
    int aux = s[i] - 'a';
    int temp = V[aux].back();
    V[aux].pop_back();
    lli real_value = sum(temp,temp);
    ans += real_value - index;
    update(0,temp,1);
    index++;
  }
  cout << ans << "\n";
  return 0;
}
