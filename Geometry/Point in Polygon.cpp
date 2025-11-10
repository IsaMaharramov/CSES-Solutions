#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
struct Point{
    int x, y;
    Point(){}
    Point(int x_, int y_) : x(x_), y(y_) {}
} polygon[1 << 10];
 
istream& operator>>(istream& in, Point& p){
    in >> p.x >> p.y;
    return in;
}
 
int cross(const Point &a, const Point &b, const Point &c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
bool onSegment(const Point &a, const Point &b, const Point &c){
    if(cross(a, b, c)) return false;
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}
 
Point p, A, B;
 
int n, m;
 
string locator(){    /// https://en.wikipedia.org/wiki/Point_in_polygon
    for(int i = 0; i < n; ++i){
        if(onSegment(polygon[i], polygon[(i + 1) % n], p)) return "BOUNDARY";
    }
 
 
    int cnt(0);
    for(int i = 0; i < n; ++i){ // ray casting
        A = (B = polygon[(i + 1) % n], polygon[i]);
        if(A.y > B.y) swap(A, B);
        if(p.y >= A.y and p.y < B.y){
            cnt += (cross(A, B, p) > 0);
        }
    }
 
    return (cnt & 1 ? "INSIDE" : "OUTSIDE");
}
 
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> polygon[i];
    }
    while(m--){
        cin >> p;
        cout << locator() << '\n';
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}