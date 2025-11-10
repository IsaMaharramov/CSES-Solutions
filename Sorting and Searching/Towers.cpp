#include<bits/stdc++.h>
using namespace std;
int n, a[200005];
multiset<int> st;
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(register int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	st.insert(a[1]);
	for(register int i = 2; i <= n; ++i){
		auto it = st.upper_bound(a[i]);
		if(it == st.end()){
			st.insert(a[i]);
		}else{
			st.erase(it);
			st.insert(a[i]);
		}
	}
	cout << (int)st.size() << '\n';
	return 0;
}
