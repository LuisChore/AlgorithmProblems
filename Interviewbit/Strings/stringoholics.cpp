#include <bits/stdc++.h>
using namespace std;
typedef long long lli;


lli mod = 1e9 + 7;

int shortest_recurring_substring(string &s){
  int n = s.size();
  vector<int> b(n+1,0);
  b[0] = -1;
  int i=0,j=-1;
  while(i<n){
    while(j>=0 && s[i] != s[j])
      j = b[j];
    i++;
    j++;
    b[i] = j;
  }
  int left_size = n - b[n];
  if(n%left_size)
    return n;
  return left_size;
}


lli gcd(lli a,lli b){
  while(b != 0){
    lli res = a % b;
    a = b;
    b = res;
  }
  return a;
}

vector<int> get_sieve(lli n){
  vector<int> sieve(n+1,0);
  for(int i=4;i<=n;i+=2)
    sieve[i] = 2;
  for(int i=3;i*i<=n;i+=2){
    if(sieve[i] == 0)
      for(int j=i*i;j<=n;j+=i*2){
        if(sieve[j] == 0)
          sieve[j] = i;
      }
  }
  return sieve;
}

vector<int> get_factors(int number,vector<int> &sieve){
  vector<int> ans;
  while(sieve[number]){
    int pr = sieve[number];
    int sum = 0;
    while(number%pr == 0){
      sum++;
      number/=pr;
    }
    ans.push_back(pr);
    ans.push_back(sum);
  }
  if(number != 1){
    ans.push_back(number);
    ans.push_back(1);
  }
  return ans;
}

vector<int> get_lcm(vector<int> &a,vector<int> &b){
  vector<int> lcm;
  int ia=0,ib=0;
  while(ia < a.size() && ib < b.size()){
    if(a[ia] == b[ib]){
      lcm.push_back(a[ia]);
      lcm.push_back(max(a[ia + 1],b[ib + 1]));
      ia +=2;
      ib +=2;
    }else if(a[ia] < b[ib]){
      lcm.push_back(a[ia]);
      lcm.push_back(a[ia + 1]);
      ia += 2;
    }else{
      lcm.push_back(b[ib]);
      lcm.push_back(b[ib + 1]);
      ib += 2;
    }
  }

  while(ia < a.size()){
    lcm.push_back(a[ia]);
    lcm.push_back(a[ia + 1]);
    ia += 2;
  }

  while(ib < b.size()){
    lcm.push_back(b[ib]);
    lcm.push_back(b[ib + 1]);
    ib += 2;
  }
  return lcm;
}


lli get_power(lli a,lli e){
  lli ans = 1;
  while(e){
    if(e&1){
      ans = (ans * a) % mod;
    }
    a = a * a % mod;
    e >>= 1;
  }
  return ans;
}

lli answer(vector<int> &factors){
  lli ans = 1;
  for(int i=0;i<factors.size();i+=2){
    ans =( ans * get_power(factors[i],factors[i+1]) ) % mod;
  }
  return ans;

}
int solve(vector<string> &A) {
  lli ans = 1;
  vector<int> factors;
  vector<int> sieve = get_sieve(200000);
  for(auto &s: A){
    int srs = shortest_recurring_substring(s);
    for(lli i = 1;i<=2*srs;i++){
      lli tr = (i) * (i + 1) >> 1LL;
      if(tr % srs == 0){
        vector<int> fsi = get_factors(i,sieve);
        factors = get_lcm(fsi,factors);
        break;
      }
    }
  }
  return answer(factors);
}


int main(){
  vector<string> A = {"a","ababa","aba"};
  cout << solve(A) << "\n";
  return 0;
}
