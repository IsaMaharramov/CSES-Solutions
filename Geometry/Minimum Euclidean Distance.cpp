#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
 
#define int long long
 
const int sz = 200005;
 
struct Point{
    int x, y;
} p[sz], temp[sz];
 
inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
 
inline int dist(const Point& a, const Point& b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
 
bool cmp_x(const Point& a, const Point& b){ return (a.x < b.x || (a.x == b.x && a.y < b.y)); }
bool cmp_y(const Point& a, const Point& b){ return a.y < b.y; }
 
int n, ans;
 
int f(int l = 0, int r = n) {
    if(r - l <= 3){
        int mnd = LLONG_MAX;
        for(int i = l; i < r; ++i){
            for(int j = i + 1; j < r; ++j) mnd = min(mnd, dist(p[i], p[j]));
        }
        sort(p + l, p + r, cmp_y);
        return mnd;
    }
 
    int mid = (l + r) >> 1;
    int mid_x = p[mid].x;
    int d = min(f(l, mid), f(mid, r));
    
    merge(p + l, p + mid, p + mid, p + r, temp, cmp_y);
    copy(temp, temp + (r - l), p + l);
    
    int ts = 0;
    for (int i = l; i < r; ++i) {
        if((p[i].x - mid_x) * (p[i].x - mid_x) >= d) continue;
 
        for(int j = ts - 1; j >= 0 && (p[i].y - temp[j].y) * (p[i].y - temp[j].y) < d; --j) d = min(d, dist(p[i], temp[j]));
 
        temp[ts++] = p[i];
    }
    
    return d;
}
 
signed main(){
    cout.tie(0)->sync_with_stdio(0);
    n = read();
    for(int i = 0; i < n; ++i){
        p[i].x = read(), p[i].y = read();
    }
    sort(p, p + n, cmp_x);
    cout << f() << '\n';
    return 0;
}