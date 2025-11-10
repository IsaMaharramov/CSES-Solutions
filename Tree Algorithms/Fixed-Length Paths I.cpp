#include "bits/stdc++.h"
using namespace std;
 
constexpr int inf = 1e9 + 7;
constexpr int sz = 2e5 + 5;
 
int n, k, subtree_size[sz], mx_depth, cnt[sz]{1};
long long ans;
vector<int> g[sz];
bitset<sz> isremoved;
 
int get_subtree_size(int node, int fa = 0) {
    subtree_size[node] = 1;
    for (auto to : g[node]) {
        if ((to ^ fa) && !isremoved[to]) {
            subtree_size[node] += get_subtree_size(to, node);
        }
    }
    return subtree_size[node];
}
 
int get_centroid(int desired, int node, int fa = 0) {
    for (auto to : g[node]) {
        if ((to ^ fa) && !isremoved[to] && (desired <= subtree_size[to])) {
            return get_centroid(desired, to, node);
        }
    }
    return node;
}
 
void get_cnt(int node, int fa, bool filling, int depth = 1) {
 
    if (depth > k) return;
 
    mx_depth = max(depth, mx_depth);
 
    if (filling) {
        cnt[depth]++;
    }else {
        ans += cnt[k - depth];
    }
 
    for (auto to : g[node]) {
        if (to ^ fa && !isremoved[to]) {
            get_cnt(to, node, filling, depth + 1);
        }
    }
 
 
}
 
 
void build(int node = 1) {
 
    int N = get_subtree_size(node);
 
    int centroid = get_centroid(N >> 1, node);
 
    isremoved[centroid] = true;
 
    mx_depth = 0;
 
    for (auto to : g[centroid]) {
        if (isremoved[to]) continue;
 
        get_cnt(to, centroid, false);
        get_cnt(to, centroid, true);
 
 
    }
 
    fill(cnt + 1, cnt + mx_depth + 1, 0);
 
    for (auto to : g[centroid]) {
        if (!isremoved[to]) {
            build(to);
        }
    }
 
 
}
 
 
signed main() {
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    build();
    cout << ans << '\n';
    return 0;
}