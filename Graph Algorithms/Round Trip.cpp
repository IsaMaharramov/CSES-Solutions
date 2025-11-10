#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<queue>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 1e5 + 5;
 
int n, m;
vector<int> g[sz];
int color[sz];
int fa[sz];
bool dfs(int node){
    color[node] = 1;
    for(auto &to : g[node]){
        if(!color[to] && to ^ fa[node]){
            fa[to] = node;
            if(dfs(to)){
                vector<int> ans;
                int x = fa[to];
                while(x ^ to){
                    ans.eb(x);
                    x = fa[x];
                }
                cout << (int)ans.size() << '\n';
                for(auto &tot : ans) cout << tot << ' ';
                exit(0);
                return true;
            }
        }else if(color[to] == 1 && to ^ fa[node]){
            vector<int> ans;
            int x = node;
            while(x ^ to){
                ans.eb(x);
                x = fa[x];
            }
            ans.eb(x), ans.eb(node);
            cout << (int)ans.size() << '\n';
            for(auto &tot : ans) cout << tot << ' ';
            exit(0);
            return true;
        }
    }
    color[node] = 2;
    return false;
}
 
signed main(){
	SPEED;
	cin >> n >> m;
	for(register int i = 0, a, b; i < m; ++i){
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
	}
	for(register int i = 1; i <= n; ++i){
        if(!color[i]){
            fa[i] = i;
            dfs(i);
        }
	}
	return puts("IMPOSSIBLE"), 0;
}