#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
const lli inf = 1e18;


lli stL[400010];
lli stR[400010];
int n;
void construct_st(lli st[],vector<int> &a,int l=0,int r = n-1,int i = 0){
  if(l == r){
    st[i] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  construct_st(st,a,l,mid,i*2+1);
  construct_st(st,a,mid + 1,r,i*2+2);
  st[i] = max(st[i*2 + 1],st[i*2 + 2]);
}

lli max_st(lli st[],int s,int e,int l=0,int r = n-1,int i = 0){
  if(e<l || s>r)
    return - inf;
  if(s<=l && r<=e)
    return st[i];
  int mid = (l + r) >> 1;
  lli L = max_st(st,s,e,l,mid,i*2+1);
  lli R = max_st(st,s,e,mid+1,r,i*2+2);
  return max(L,R);
}

vector<pair<int,int>> greater_index(vector<int> &v){
  stack<int> Stack;
  vector<pair<int,int>> a(v.size(),{-1,v.size()});
  for(int i=0;i<v.size();i++){
    while(Stack.size() && v[Stack.top()] < v[i]){
      a[Stack.top()].second = i;
      Stack.pop();
    }
    Stack.push(i);
  }
  while(Stack.size())
    Stack.pop();

  for(int i=v.size()-1;i>=0;i--){
    while(Stack.size() && v[Stack.top()] < v[i]){
      a[Stack.top()].first = i;
      Stack.pop();
    }
    Stack.push(i);
  }
  return a;
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int> v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  vector<pair<int,int>> a = greater_index(v);
  vector<int> L(n),R(n);
  int sum = 0;
  for(int i=0;i<n;i++){
    L[i] = v[i];
    if(i)
      L[i] += L[i-1];
  }

  sum = 0;
  for(int i=n-1;i>=0;i--){
    R[i] = v[i];
    if(i < n-1)
      R[i] += R[i+1];
  }
  construct_st(stL,L);
  construct_st(stR,R);
  lli ans = 0;
  for(int i=0;i<n;i++){
    pair<int,int> aux = a[i];
    aux.first++;
    aux.second--;
    lli temp1 = max_st(stR,aux.first,i) - R[i];
    lli temp2 = max_st(stL,i,aux.second) - L[i];
    temp1 = max(temp1,0LL);
    temp2 = max(temp2,0LL);
    ans = max(ans,temp1 + temp2);

  }
  cout << ans << "\n";


  return 0;
}
