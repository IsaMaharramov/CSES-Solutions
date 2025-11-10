/// https://en.wikipedia.org/wiki/Shoelace_formula
/// https://en.wikipedia.org/wiki/Pick%27s_theorem
/// http://www.geometer.org/mathcircles/pick.pdf
/// https://cp-algorithms.com/geometry/picks-theorem.html
#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 1e5 + 5;
constexpr int mod = 1e9 + 7;
 
struct Point{
    int x, y;
    Point(){}
    Point(int x_, int y_) : x(x_), y(y_) {}
} polygon[sz];
 
istream& operator>>(istream& in, Point& p){
    in >> p.x >> p.y;
    return in;
}
 
int n;
 
void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> polygon[i];
    }
    int area_2times = 0;
    for(int i = 0; i<n; ++i){  /// Shoelace_formula
        area_2times += (polygon[i].x * polygon[(i + 1) % n].y - polygon[(i + 1) % n].x * polygon[i].y);
    }
    area_2times = abs(area_2times);
 
    int cnt = 0; // boundary_points
    for(int i = 0; i < n; ++i){
        cnt += __gcd(abs(polygon[(i + 1) % n].x - polygon[i].x), abs(polygon[(i + 1) % n].y - polygon[i].y));
    }
 
    /*
    Pick's theorem:
    A = I + (b / 2) - 1
    So:
        area_2times / 2 = I + cnt / 2 - 1
        I = (area_2times - cnt) / 2 + 1
    */
 
    int I = ((area_2times - cnt) >> 1) + 1;
    cout << I << ' ' << cnt << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}