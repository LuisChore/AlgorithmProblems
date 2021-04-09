#include <iostream>
using namespace std;


int gcd(int a,int b){
  while(b){
    int r = a%b;
    a = b;
    b = r;
  }
  return a;
}

int isPower(int A) {
  if(A == 1)
    return 1;
  int g = 0;
  for(int j=2;j * j <= A;j++){
    int sum = 0;
    while(A % j == 0){
      A/=j;
      sum++;
    }
    g = gcd(sum,g);
  }
  return (A == 1 && g > 1);
}

int main(){
  int n;
  while(cin >> n){
    cout << isPower(n) << "\n";
  }
  return 0;
}
