#include<iostream>
#include<vector>
#include<queue>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
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
#define left leftttt
 
using namespace std;
using ld = long double;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define int ll
 
const int sz = 2e5 + 5;
 
int n;
 
int powr(int a, int b){
    if(!b) return 1;
    return (b & 1) ? a * powr(a, b - 1) : powr(a*a, b >> 1);
}
 
signed main(){
    SPEED;
    int T;
    cin >> T;
    auto test_case = [&](){
        cin >> n;
        int c(1);
        int p{9};
        while(n - p > 0){
            n -= p;
            ++c;
            p = 9 * powr(10, c - 1) * c;
        }
        --n;
        int x = n / c;
        int y = n % c;
        int ans = powr(10, c - 1) + x;
        string s = to_string(ans);
        cout << s[y] << '\n';
        return;
    };
    while(T--) test_case();
    return 0;
}