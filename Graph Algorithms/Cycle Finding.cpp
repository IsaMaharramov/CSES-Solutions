#include<iostream>
#include<vector>
#include<algorithm>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(v) v.begin(),v.end()
#define eb emplace_back
using namespace std;
struct edge{
    int u, v, dist;
};
const long long inf = 1e18 - 1;
vector<int> parent;
vector<long long> d;
void init(int &n){
    parent.resize(n+1);
    d.resize(n+1);
    for(int i = 0; i <= n; ++i) d[i] = inf;
}
void Ford_Bellman(){
    int n, m;
    cin >> n >> m;
    init(n);
    vector<edge> e(m);
    for(int i = 0; i < m; ++i){
        cin >> e[i].u >> e[i].v >> e[i].dist;
        if(e[i].u == e[i].v and e[i].dist < 0){
            cout << "YES" << '\n' << e[i].u << ' ' << e[i].v << '\n';
            return;
        }
    }
    d[1] = 0;
    parent[1] = -1;
    int cur = -1;
    for(int i = 0; i < n; ++i){
                            cur = -1;
        for(edge temp : e){
 
                if(d[temp.v] > d[temp.u] + temp.dist){
                    d[temp.v] =  d[temp.u] + temp.dist;
                    parent[temp.v] = temp.u;
                    cur = temp.v;
 
                }
        }
    }
    if(cur == -1){
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    vector<int> cycle;
 
    for(int i = 0; i < n; ++i)
        cur = parent[cur];
 
    int in_cur = cur;
    cycle.eb(cur);
    cur = parent[cur];
    while(cur != in_cur){
        cycle.eb(cur);
        cur = parent[cur];
    }
    cycle.eb(cur);
 
 
//  for (int v = cur;; v = parent[v]) {
//            cycle.push_back(v);
//            if (v == cur && cycle.size() > 1)
//                break;
//        }
 
 
 
 
 
    reverse(all(cycle));
    for(int node:cycle)
        cout << node << ' ';
    cout << '\n';
}
int main(){
    fast_io;
    Ford_Bellman();
    exit(0);
}