#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
 
constexpr int inf = 1e9 + 7;
constexpr int sz = 1e5 + 5;
 
int n, m, k;
vector<int> ans[sz];
vector<pii> g[sz];
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1, a, b, w; i <= m; ++i) {
        cin >> a >> b >> w;
        g[a].eb(pii{b, w});
    }
 
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();
        if (ans[u].size() == k) continue;
        ans[u].eb(d);
        for (pii& to : g[u]) {
            pq.push(pii{d + to.second, to.first});
        }
    }
    sort(all(ans[n]));
    for (int& to : ans[n]) cout << to << ' ';
    exit(0);
}