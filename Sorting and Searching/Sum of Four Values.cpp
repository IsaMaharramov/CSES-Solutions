#include<bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#endif
 
template<class T>void in(T &x) {
    x = 0; bool f = 0; char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = 1; c = getchar();}
    while ('0' <= c && c <= '9') {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
    if (f) x = -x;
}
 
#define int long long
 
int n, x, a[1001];
 
map<int, vector<pair<int, int>>> mp;
 
signed main(){
	in(n), in(x);
	vector<int> b = {0};
	for(register int i = 1; i <= n; ++i){
		in(a[i]);
		b.emplace_back(a[i]); 
	}
	if(n < 4) return puts("IMPOSSIBLE"), 0;
	
	sort(b.begin(), b.end());
	
	if((b[n] + b[n-1] + b[n-2] + b[n-3]) < x) return puts("IMPOSSIBLE"), 0;
	int tot = b[n] + b[n-1];
	b.clear();
	for(register int i = 1; i <= n; ++i){
		for(register int j = i + 1; j <= n; ++j){
			if((a[i] + a[j] > x) || (a[i] + a[j] + tot < x)) continue;
			mp[a[i] + a[j]].emplace_back(pair<int, int>{i, j});
		}
	}
	
	for(auto &to : mp){
		
		int sm = to.first;
		vector<pair<int, int>> c = to.second;
		int y = x - sm;
		vector<pair<int, int>> d = mp[y];
		
		for(auto &i : c){
			for(auto &j : d){
				set<int> st = {i.first, j.first, i.second, j.second};
				if((int)st.size() < 4) continue;
				for(auto &toto : st) cout << toto << ' ';
				return puts(""), 0;
			}
		}
		
	}
	
	cout << "IMPOSSIBLE" << '\n';
	
	
}