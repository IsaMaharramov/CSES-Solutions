#include<bits/stdc++.h>
using namespace std;
 
inline int read();
 
 
int n, m, fa[100005], sizel[100005], mx, components;
 
inline int find_set(int v){
	return fa[v]==v?v:fa[v]=find_set(fa[v]);
}
 
 
inline void Union(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a ^ b){
		if(sizel[a] > sizel[b]) swap(a, b);
		sizel[b] += sizel[a];
		mx = max(mx, sizel[b]);
		--components;
		fa[a] = fa[b];
	}
	return;
}
 
 
inline void init(){
	components = n;
	for(register int i = 1; i <= n; ++i) fa[i] = i, sizel[i] = 1;
	return;
}
 
 
signed main(){
	n = read(), m = read();
	init();
	for(register int i = 1, u, v; i <= m; ++i){
		u = read(), v = read();
		Union(u, v);
		cout << components << ' ' << mx << '\n';
	}
	return 0;
}
 
 
inline int read() {
  //  opt = 0;
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    //if (ch == ' ') opt = 1;
    return x * f;
}