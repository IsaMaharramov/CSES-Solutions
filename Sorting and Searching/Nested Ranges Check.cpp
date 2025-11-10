#include<bits/stdc++.h>
using namespace std;
//#define DEBUG
 
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
 
constexpr int sz = (int)2e5 + 5;
 
int n, tot;
 
struct obe{
	int x, y, j;
	
	bool operator<(const obe &c)const{
		if(y ^ c.y) return y < c.y;
		return x > c.x; 
	}
	
} q[sz];
 
int tree[sz << 1];
 
inline void update(int pos, int val){
	while(pos <= tot){
		tree[pos] += val;
		pos += (pos & (-pos));
	}
	return;
}
 
inline int get_ans(int l, int r){
	if(l ^ 1) return get_ans(1, r) - get_ans(1, l - 1);
	int res(0);
	while(r > 0){
		res += tree[r];
		r -= (r & (-r));
	}
	return res;
}
 
bitset<sz> ans;
 
map<int, int> mp;
 
signed main(){
	in(n);
	for(register int i = 1; i <= n; ++i){
		in(q[i].x), in(q[i].y), q[i].j = i;
		mp[q[i].x], mp[q[i].y];
	}
	
	for(auto &to : mp) to.second = ++tot;
	for(register int i = 1; i <= n; ++i){
		q[i].x = mp[q[i].x], q[i].y = mp[q[i].y];
	}
	++tot;
	sort(q+1, q+n+1);
	debug(tot);
 
	for(register int i = 1; i <= n; ++i){
		
		
		ans[q[i].j] = get_ans(q[i].x, q[i].y);
		
		
		update(q[i].x, 1);
		
		
	}
	
	
	for(register int i = 1; i <= n; ++i){
		cout << ans[i] << ' ';
	}
	
	cout << '\n';
	
	
	memset(tree, 0, sizeof(tree));
	
	ans.reset();
	
	for(register int i = 1; i <= n; ++i){
		
		update(q[i].x, 1);
	
	}
 
	for(register int i = 1; i <= n; ++i){
		
		update(q[i].x, -1);
		
		ans[q[i].j] = get_ans(1, q[i].x);
		
	}
	
	for(register int i = 1; i <= n; ++i){
		cout << ans[i] << ' ';
	}
	
}
/*
 
1 2 3 4 5 6 7 8
1 0 1 1 0 0 0 0 
 
2 4
 
3 6
 
1 6
 
4 8 
 
 
 
 
*/