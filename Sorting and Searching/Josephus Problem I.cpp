#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
 
using namespace __gnu_pbds;
#define ordered_set  tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5;
 
int n, k;
 
signed main(){
    SPEED;
    in(n), k = 1;//, in(k);
    ordered_set ost;
    for(register int i = 1; i <= n; ++i) ost.insert(i);
    int cur_pos(0);
    while((int)ost.size()){
        cur_pos = (cur_pos + k) % (int)ost.size();
        auto tot = ost.find_by_order(cur_pos);
        cout << *tot << '\n';
        ost.erase(tot);
    }
    return 0;
}