// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e6 + 6;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 7;
 
struct Event {
    int x, y, type;  // type -> 0 = horizontal start  1 = vertical 2 = horizontal end
    int y2;          // vertical -> y2
};
 
class Fenwick{
private:
    vector<int> bit;
public:
    Fenwick(int n) : bit(n + 10, 0) {}
    
    void update(int pos, int val){
        ++pos;
        while(pos < (int)bit.size()){
            bit[pos] += val;
            pos += (pos & -pos);
        }
    }
    
    int query(int r){
        ++r;
        int res(0);
        while(r > 0){
            res += bit[r];
            r -= (r & -r);
        }
        return res;
    }
    
    int get_ans(int l, int r){
        return query(r) - query(l - 1);
    }
};
 
 
void solve(){
    int n;
    cin >> n;
    vector<Event> events;
    for(int i = 0, x1, x2, y1, y2; i < n; ++i){
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += (int)1e6 + 1; y1 += (int)1e6 + 1; x2 += (int)1e6 + 1; y2 += (int)1e6 + 1;
        if(y1 == y2){ 
            if(x1 > x2) swap(x1, x2);
            events.emplace_back(Event{x1, y1, 0, 0}), events.emplace_back(Event{x2, y1, 2, 0});
        }else{
            if(y1 > y2) swap(y1, y2);
            events.emplace_back(Event{x1, y1, 1, y2});
        }
    }
    
    sort(events.begin(), events.end(), [&](const Event& a, const Event& b){ return ((a.x != b.x) ? a.x < b.x : a.type < b.type); });
    
    Fenwick bit(sz);
    int ans(0);
    for(const Event& e : events){
        if(e.type ^ 1) bit.update(e.y, (e.type ? -1 : 1));
        else ans += bit.get_ans(e.y, e.y2);
    }
    cout << ans << '\n';
}
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int T{1};
  //cin >> T;
  while(T--) solve();
  return 0;
}