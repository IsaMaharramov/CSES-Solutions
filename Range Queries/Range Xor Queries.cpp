#include<iostream>
#include<random>
#include<chrono>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define f first
#define s second
 
using namespace std;
using ll = long long;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 1e5 + 3;
 
 
template <typename T>
struct BIT{
    int N;
    vector<T>tree;
    BIT(int n){
        N = n;
        tree.assign(N+1,0);
    }
    void update(int pos, T val){
        while(pos <= N){
            tree[pos] ^= val;
            pos += (pos & (-pos));
        }
    }
    T sum(int l, int r){
        if(l != 1) return (sum(1, r) ^ sum(1, l - 1));
        T res(0);
        while(r > 0){
            res ^= tree[r];
            r -= (r & (-r));
        }
        return res;
    }
};    // BIT<int> bit(Size); usage
 
void Fenwick(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n+1);
    BIT<ll> bit(n);
    for(register int i = 1; i <= n; ++i){
        cin >> arr[i];
        bit.update(i, (ll)arr[i]);
    }
    int  l, r;
    while(q--){
            cin >> l >> r;
                cout << bit.sum(l, (ll)r) << '\n';
    }
 
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Fenwick();
 
 
    return 0;
}
