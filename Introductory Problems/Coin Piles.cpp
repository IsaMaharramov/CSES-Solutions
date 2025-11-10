#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_set>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5, MOD = 1e9 + 7;
 
#define int ll
 
int a, b;
 
signed main(){
    SPEED;
    int T;
    cin >> T;
    while(T--){
        cin >> a >> b;
        if((a + b) % 3){
        	cout << "NO" << '\n';
        	continue;
        }
        if(a > b) swap(a, b);
        cout << ((b + 1) / 2 <= a ? "YES" : "NO") << '\n';
    }
    return 0;
}