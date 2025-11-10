/// https://sites.science.oregonstate.edu/math_reu/proceedings/REU_Proceedings/Proceedings2004/2004Ganzfried.pdf
/// https://www.geeksforgeeks.org/dsa/warnsdorffs-algorithm-knights-tour-problem/
#include "bits/stdc++.h" 
using namespace std;
 
// #define int long long
 
// constexpr int inf = 1e18 + 7;
 
int g[1 << 3][1 << 3];
 
array<int, 8> dx = {-2, -2, -1, -1, 1, 1, 2, 2}, dy = {-1, 1, -2, 2, -2, 2, -1, 1};
 
bool isOK(int x, int y){
    return (min(x, y) >= 0 and max(x, y) < 8 and !g[x][y]);
}
 
int get_degree(int x, int y){
    int cnt = 0;
    for(int i = 0; i < 8; ++i) cnt += isOK(x + dx[i], y + dy[i]);
    return cnt;
}   
 
void solve(){
    int X, Y;
    cin >> X >> Y;    
    swap(X, Y);
    memset(g, 0, sizeof(g));
 
    function<bool(int, int, int)> Dfs = [&](int x, int y, int step)->bool{
        g[x][y] = step;
        if(step == 64) return true;
 
        vector<array<int, 3>> nxt;
 
        for(int i = 0; i < 8; ++i){
            int tox = x + dx[i], toy = y + dy[i];
            if(!isOK(tox, toy)) continue;
            nxt.emplace_back(array<int, 3>{get_degree(tox, toy), tox, toy});
        }
 
        sort(nxt.begin(), nxt.end());
        for(auto &j : nxt){
            if(Dfs(j[1], j[2], step + 1)){
                return true;
            }
        }
 
        g[x][y] = 0;
 
        return false;
    };
 
    Dfs(X - 1, Y - 1, 1);
 
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            cout << g[i][j] << " \n"[(j + 1) == 8];
        }
    }
 
    return;
}
 
signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}