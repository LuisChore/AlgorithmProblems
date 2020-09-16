#include <iostream>
#include <vector>
using namespace std;

int main(){
  long long n;
  cin >> n;
  vector<long long> v(n);
  for(int i=0;i<n;i++)
    cin >> v[i];
  if(n == 1){
    cout << 1 << " " << 1 << "\n"<< - v[0] << "\n";
    cout << 1 << " " << 1 << "\n"<< 0 << "\n";
    cout << 1 << " " << 1 << "\n"<< 0 << "\n";
    return 0;
  }
  cout << 1 << " " << (n-1) << "\n";
  for(int i=0;i<n-1;i++){
    long long res = v[i] % n;
    if(res < 0)
      res = n +  res;
    cout << res * (n-1LL) << " ";
    v[i] += res * (n-1LL);
  }
  cout << "\n";
  cout << 1 << " " << n << "\n";
  for(int i = 0; i < n-1; i++){
    cout << - v[i] << " ";
  }
  cout << "0\n";
  cout << n << " " << n << "\n";
  cout << -v[n-1] << "\n";
  return 0;
}
