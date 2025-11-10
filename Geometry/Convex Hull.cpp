#include "bits/stdc++.h"
using namespace std;
#define int long long
 
struct pt { ///  https://cp-algorithms.com/geometry/convex-hull.html
    int x, y;
};
 
int orientation(pt a, pt b, pt c) {
    int v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}
 
bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool ccw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}
 
bool cmp(pt a, pt b){
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
 
void convex_hull(vector<pt>& a, bool include_collinear = false) {
    if (a.size() == 1)
        return;
    sort(a.begin(), a.end(), cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
            while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i], include_collinear))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
 
    if (include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}
const int sz = 2e5 + 5;
int n; 
void solve(){
    cin >> n;
    vector<pt> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].x >> v[i].y;
    }
    convex_hull(v, true);
    n = (int)v.size();
    cout << n << '\n';
    for(int i = 0; i < n; ++i) cout << v[i].x << ' ' << v[i].y << '\n';
}
 
signed main(){
	ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}