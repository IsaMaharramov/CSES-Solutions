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
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define f first
#define s second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
#define left lefttt
#define right righttt
 
//using namespace __gnu_pbds;
//template<class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5;
 
template<typename T>
struct BIT_2D{
    int N, M;
    vector<vector<T>>tree;
    BIT_2D(int n, int m){
        N = n;
        M = m;
        tree.assign(N+1, vector<T>(M+1, 0));
    }
    void update(int x, int y, T val){
        for(int i = x; i <= N; i += (i & (-i))){
            for(int j = y; j <= M; j += (j & (-j))){
                tree[i][j] += val;
            }
        }
    }
    T sum(int xl, int yl, int xr, int yr){
        if(!(xl == 1 && yl == 1)){
            return sum(1, 1, xr, yr) - sum(1, 1, xl - 1, yr) - sum(1, 1, xr, yl - 1) + sum(1, 1, xl - 1, yl - 1);
        }
        T res(0);
        for(int i = xr; i > 0; i -= (i & (-i))){
            for(int j = yr; j > 0; j -= (j & (-j))){
                res += tree[i][j];
            }
        }
        return res;
    }
};   // BIT_2D<ll> bit(n, n); usage
 
int n, q;
 
char ch;
 
signed main(){
    SPEED;
    cin >> n >> q;
    BIT_2D<int> bit(n, n);
    for(register int i = 1; i <= n; ++i){
        for(register int j = 1; j <= n; ++j){
            cin >> ch;
            if(ch == '*'){
                bit.update(i, j, 1);
            }
        }
    }
    int type, x1, y1, x2, y2, y, x;
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> x >> y;
            int val = bit.sum(x, y, x, y);
            val = (val ? -1 : 1);
            bit.update(x, y, val);
        }else{
            cin >> x1 >> y1 >> x2 >> y2;
            cout << bit.sum(x1, y1, x2, y2) << '\n';
        }
    }
    return 0;
}