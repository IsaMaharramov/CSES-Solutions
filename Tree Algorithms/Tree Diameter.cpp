#include<iostream>
#include<vector>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<vector<int>> g;
void init(int &n){
    g.resize(n+1);
}
int max_node = -1, max_dist = -1;
void dfs(int node, int par = 1,int dist = 0){
 
    if(max_dist < dist){
        max_dist = dist;
        max_node = node;
    }
 
    for(int to:g[node]){
        if(to != par){
            dfs(to,node,dist+1);
        }
    }
}
int main(){
    fast_io;
    int n;
    cin >> n;
    init(n);
    for(int i = 0, u, v; i < n - 1; ++i){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1);
    dfs(max_node,max_node);
    cout << max_dist << '\n';
    exit(0);
}