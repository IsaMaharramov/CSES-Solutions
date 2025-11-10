#include<bits/stdc++.h>
 
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#endif
 
template<class T>void in(T &x) {
    x = 0; bool f = 0; char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = (c = getchar(), 1);}
    while ('0' <= c && c <= '9') {c = (x = (x << 3) + (x << 1) + (c ^ 48), getchar());}
    if (f) x = -x;
}
 
constexpr int sz = (int)2e5 + 5;
 
int n, ans, tot, ansl[sz];
 
std::array<int, 3> a[sz];
 
signed main(){
	in(n);
	
	for(register int i = 1; i <= n; ++i) a[i][2] = (in(a[i][0]), in(a[i][1]), i);
	
	std::sort(a+1, a+n+1, [&](std::array<int, 3> i, std::array<int, 3> j){ return (i[0] ^ j[0]) ? (i[0] < j[0]) : (i[1] < j[1]); });
	
	std::multiset<std::array<int, 2>> st;
	
	for(register int i = 1; i <= n; ++i){
		int s = a[i][0], f = a[i][1], j = a[i][2];
		if(st.empty()){
			
			st.insert(std::array<int, 2>{f, ++tot});
			
			ansl[j] = tot;
			
			ans = std::max(ans, tot);
			
		}else{
			
			std::array<int, 2> top = *st.begin();
			
			if(top[0] < s){
				st.erase(top);
				top = std::array<int, 2>{f, top[1]};
				ansl[j] = top[1];
				st.insert(top);
			}else{
				ans = std::max(ans, ++tot);
				ansl[j] = tot;
				st.insert(std::array<int, 2>{f, tot});
			}
			
		}
		
	}
	
	printf("%d\n", ans);
	
	for(register int i = 1; i <= n; ++i) printf("%d ", ansl[i]);
	
	printf("\n");
	
}