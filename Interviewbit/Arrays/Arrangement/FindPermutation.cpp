#include <bits/stdc++.h>
using namespace std;

vector<int> findPerm(const string A, int B) {
    vector<int> v(B,0);
    int low = 1,high = B;
    if(A[0] == 'I')
        v[0] = low++;
    for(int i=1;i<A.size();i++){
        if(A[i] == 'I' && A[i-1] == 'D'){
            v[i] = low ++;
        }
    }

    if(v[0] == 0){
        int j = 0;
        while(j<B && v[j] == 0){
            v[j++] = high--;
        }
    }
    for(int i=1;i<B-1;i++){
        if(v[i] == 0 && A[i] == 'D' && A[i-1] == 'I'){
            int j= i;
            while(j>=0 && v[j] == 0){
                v[j--] = high--;
            }
            j = i + 1;
            while(j<B && v[j] == 0){
                v[j++] = high--;
            }
        }
    }
    if(v[B-1] == 0){
        int j = B-1;
        while(j>=0 && v[j] == 0){
            v[j--] = high --;
        }
    }
    return v;
}


int main(){
}
