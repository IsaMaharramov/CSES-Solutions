#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_set>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 1e5 + 5;
 
 
vector<int> g[sz];
 
int n, m;
 
int fa[sz], sizel[sz];
 
int find_set(int v){
	if(fa[v] == v)
		return v;
	return fa[v] = find_set(fa[v]);
}
 
inline void Union(int& a, int& b){
	a = find_set(a);
	b = find_set(b);
	if(a ^ b){
		if(sizel[a] > sizel[b])
			swap(a, b);
		sizel[b] += sizel[a];
		fa[a] = fa[b];
	}
	return;
}
 
 
inline void init(){
	for(register int i = 1; i <= n; ++i) fa[i] = i, sizel[i] = 1;
	return;
}
 
map<int, int> mp;
 
signed main(){
	SPEED;
	cin >> n >> m;
	init();
	for(register int i = 1, a, b; i <= m; ++i){
		cin >> a >> b;
		Union(a, b);
	}
 
	for(register int i = 1; i <= n; ++i){
		mp[find_set(i)] = i;
	}
	set<int> st;
	for(auto &tot : mp) st.insert(tot.S);
	n = (int)st.size() - 1;
	cout << n << '\n';
	if(!n) return 0;
	auto it = st.begin();
	auto itr = st.end();
	--itr;
	while(it != itr){
        cout << *it << ' ' << *(++it) << '\n';
	}
	return 0;
}