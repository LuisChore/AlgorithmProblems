#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	int cases;
	cin >> cases;
	while(cases--){
		int n,q;
		string s;
		cin >> n >> q >> s;
		vector<pair<int,int>> L(n+2),R(n+2);
		vector<int> v(n+1,0);
		int value = 0;
		L[0] = {0,0};
		for(int i=0;i<n;i++){
			value += ((s[i] == '+') ? 1: -1);
			int index = i + 1;
			v[index] = value;
			L[index] = L[index-1];
			L[index].first = min(L[index].first,value);
			L[index].second = max(L[index].second,value);
			
		}

		R[n] = {v[n],v[n]};
	
		for(int i=n-1;i>=1;i--){
			R[i].first = min(v[i],R[i+1].first);
			R[i].second = max(v[i],R[i+1].second);
		}

		while(q--){
			int l,r;
			cin >> l >> r;
			pair<int,int> ans = L[l-1];
			int value = v[l-1];
			if(r != n){
				pair<int,int> temp = R[r+1];
				temp.first -= v[r];
				temp.second -= v[r];
				temp.first += v[l-1];
				temp.second += v[l-1];
				ans.first = min(ans.first,temp.first);
				ans.second = max(ans.second,temp.second);
			}
			cout << ans.second - ans.first + 1 << "\n";

		}
	}
	return 0;
}
