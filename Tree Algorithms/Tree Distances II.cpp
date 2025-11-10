#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define in(x) scanf("%d",&x)
#define IN(x) scanf("%I64d",&x)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
#define left lefttt
#define right righttt
#define y1 y_1
 
//using namespace __gnu_pbds;
//template<class T> using ost = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5;
 
#define int ll
 
int n;
 
set<int> g[sz];
int subtree_size[sz], depth[sz];
 
int ans[sz];
 
int dfs(int node, int fa){
    subtree_size[node] = 1;
    for(auto &to : g[node]){
        if(to ^ fa){
            subtree_size[node] += dfs(to, node);
        }
    }
    return subtree_size[node];
}
 
 
inline void DFS(int node, int fa){
    for(auto &to : g[node]){
        if(to ^ fa){
            depth[to] = depth[node] + 1;
            DFS(to, node);
        }
    }
    return;
}
 
inline void dfsl(int node, int fa){
    if(node ^ 1){
        ans[node] = ans[fa] - subtree_size[node] + (n - subtree_size[node]);
       // cout<<"OK"<<endl;
    }
    for(auto &to : g[node]){
        if(to ^ fa){
            dfsl(to, node);
        }
    }
    return;
}
 
 
/*
ans[i] = ans[1] - subtree[i] * d[i] + (n - subtree[i]) * d[i];
*/
 
signed main(){
    SPEED;
    cin >> n;
    for(register int i = 1, a, b; i < n; ++i){
        cin >> a >> b;
        g[a].insert(b), g[b].insert(a);
    }
    dfs(1, 1);
    DFS(1, 1);
    for(register int i = 1; i <= n; ++i){
        ans[1] += depth[i];
    }
    dfsl(1, 1);
    //for(register int i = 2; i <= n; ++i){
       // ans[i] = ans[1] - subtree_size[i] * depth[i] + (n - subtree_size[i]) * depth[i];
    //}
    for(register int i = 1; i <= n; ++i){
        cout << ans[i] << ' ';
      //  cout << "subtree : " << subtree_size[i] << '\n' << "depth : " << depth[i] << endl;
    }
    return 0;
}