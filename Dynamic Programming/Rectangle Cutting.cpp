#include<iostream>
#include<vector>
#include<queue>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
#define right righttttt
#define left lefttttt
 
using namespace std;
using ld = long double;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define int ll
 
const int sz = 2e5 + 5;
 
int dp[505][505];
 
int get_ans(int a, int b){
    if(b < 0 || a < 0) return oo;
    if(a > b) swap(a, b);
    if(a == b) return 0ll;
    if(dp[a][b]) return dp[a][b];
    int tmp, res{oo};
    for(register int i = 1; i < b; ++i){
        tmp = get_ans(a, i) + 1 + get_ans(a, b - i);
        res = min(res, tmp);
    }
    for(register int i = 1; i < a; ++i){
        tmp = get_ans(i, b) + 1 + get_ans(a - i, b);
        res = min(res, tmp);
    }
    return dp[a][b] = res;
}
 
int a, b;
 
signed main(){
    SPEED;
    cin >> a >> b;
    if(a > b) swap(a, b);
    cout << get_ans(a, b) << '\n';
    return 0;
}