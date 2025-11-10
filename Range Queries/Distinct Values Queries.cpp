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
 
int n, q;
int x[sz];
 
template<typename T>
struct BIT{
    int N;
    vector<T>tree;
    BIT(int n){
        N = n;
        tree.assign(N+1,0);
    }
    void update(int pos, T val){
        while(pos <= N){
            tree[pos] += val;
            pos += (pos & (-pos));
        }
    }
    T sum(int l, int r){
        if(l != 1) return sum(1, r) - sum(1, l - 1);
        T res(0);
        while(r > 0){
            res += tree[r];
            r -= (r & (-r));
        }
        return res;
    }
};    // BIT<int> bit(Size); usage
 
vector<pii> queries[sz];
 
map<int, int> last_indexs;
 
signed main(){
    SPEED;
    cin >> n >> q;
    for(register int i = 1; i <= n; ++i){
        cin >> x[i];
    }
    int l, r;
    for(register int j = 1; j <= q; ++j){
        cin >> l >> r;
        queries[l].push_back({r, j});
    }
 
    BIT<int> bit(n);
 
    vector<int> answers(q+1, 0);
 
    for(register int i = n; i >= 1; --i){
        int val = x[i];
        if(last_indexs.count(val))
            bit.update(last_indexs[val], -1);
        last_indexs[val] = i;
        bit.update(i, 1);
        for(auto &tot : queries[i]){
            answers[tot.s] = bit.sum(i, tot.f);
        }
    }
 
    for(register int i = 1; i <= q; ++i){
        cout << answers[i] << '\n';
    }
 
    return 0;
}