#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
struct Point{
    int x, y;
} p1, q1, p2, q2;
 
istream& operator>>(istream& in, Point& p){
    in >> p.x >> p.y;
    return in;
}
 
int orient(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(!val) return 0; // collinear
    return ((val > 0) ? 1 : 2); // clock or counterclock
}
 
bool onSegment(Point p, Point q, Point r){
    return (min(p.x, r.x) <= q.x and q.x <= max(p.x, r.x) and min(p.y, r.y) <= q.y and q.y <= max(p.y, r.y));
}
 
bool intersect(Point p1, Point q1, Point p2, Point q2){
    array<int, 4> o = {orient(p1, q1, p2), orient(p1, q1, q2), orient(p2, q2, p1), orient(p2, q2, q1)};
    bool flag = ((o[0] ^ o[1]) && (o[2] ^ o[3]));
    flag |= (!o[0] && onSegment(p1, p2, q1));
    flag |= (!o[1] && onSegment(p1, q2, q1));
    flag |= (!o[2] && onSegment(p2, p1, q2));
    flag |= (!o[3] && onSegment(p2, q1, q2));
    return flag;
}
 
void solve(){
    cin >> p1 >> q1 >> p2 >> q2;
    puts((intersect(p1, q1, p2, q2) ? "YES" : "NO"));
}
 
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    cin >> T;
    while(T--) solve();
    return 0;
}