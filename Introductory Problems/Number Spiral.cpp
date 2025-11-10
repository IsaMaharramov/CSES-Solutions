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
 
int x, y;
 
signed main(){
    SPEED;
    int T;
    cin >> T;
    auto test_case = [&](){
    	cin >> x >> y;
    	if(x & 1){
            if(x > y){
                cout << (x - 1) * (x - 1) + y << '\n';
            }else{
                cout << ((y & 1) ? (y * y - x + 1) : ((y - 1) * (y - 1) + x)) << '\n';
            }
    	}else{
    	    if(x > y){
    	        cout << ((y & 1) ? (x * x - y + 1) : (x * x - y + 1)) << '\n';
    	    }else{
    	        cout << ((y & 1) ? (y * y - x + 1) : ((y - 1) * (y - 1) + x)) << '\n';
    	    }
    	}
    };
    while(T--) test_case();
    return 0;
}