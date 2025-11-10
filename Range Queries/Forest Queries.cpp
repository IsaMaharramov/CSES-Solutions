#include<iostream>
#include<random>
#include<chrono>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<set>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define f first
#define s second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 1001;
 
int n, q;
 
char ch;
 
int a[sz][sz];
 
ll pref_sum[sz][sz];
 
signed main(){
    SPEED;
    cin >> n >> q;
    for(register int i = 1; i <= n; ++i){
        for(register int j = 1; j <= n; ++j){
            cin >> ch;
            a[i][j] = (ch == '*');
        }
    }
    for(register int i = 1; i <= n; ++i){
        for(register int j = 1; j <= n; ++j){
            pref_sum[i][j] = a[i][j] + pref_sum[i-1][j] + pref_sum[i][j-1] - pref_sum[i-1][j-1];
        }
    }
    int x1, x2, y1, y2;
    for(register int i = 1; i <= q; ++i){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pref_sum[x2][y2] - pref_sum[x1- 1][y2] - pref_sum[x2][y1 - 1] + pref_sum[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}