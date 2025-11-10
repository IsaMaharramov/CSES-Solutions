#include <iostream>   /// https://wiki.algocode.ru/index.php?title=Merge_sort_tree
#include <algorithm>
#include <vector>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")
using namespace std;
constexpr int N = 1 << 18;
 
vector<int> tree[N << 1];
 
int get_ans(int a, int b, int c, int d){
    a += N;
    b += N;
    int res(0);
    /*
    loop:
    goto loop; -> TLE
 
    while -> AC
    */
    while(a <= b){
        if(a & 1){
            res += upper_bound(tree[a].begin(), tree[a].end(), d) - lower_bound(tree[a].begin(), tree[a].end(), c);
            ++a;
        }
        if(!(b & 1)){
            res += upper_bound(tree[b].begin(), tree[b].end(), d) - lower_bound(tree[b].begin(), tree[b].end(), c);
            --b;
        }
        a >>= 1;
        b >>= 1;
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1, x; i <= n; ++i){
        cin >> x;
        tree[N + i] = {x};
    }
    for(int node = N - 1; node; --node){   /// Thanks -> Otherwordly -> https://codeforces.com/profile/Otherwordly
        merge(tree[node << 1].begin(), tree[node << 1].end(), tree[(node << 1) + 1].begin(), tree[(node << 1) + 1].end(), back_inserter(tree[node])); /// https://en.cppreference.com/w/cpp/iterator/back_inserter.html
        /*
        node << 1 | 1 -> TLE
        (node << 1) + 1  -> AC
        */
    }
    int a, b, c, d;
    while(q--){
        cin >> a >> b >> c >> d;
        cout << get_ans(a, b, c, d) << "\n";
    }
}