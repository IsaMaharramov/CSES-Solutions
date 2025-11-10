#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<map>
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
#define y1 y_1
 
using namespace std;
using ld = long double;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5;
 
#define int ll
 
int n, k;
int a[sz];
 
bool check(int max_sm){
    int subarr_count(0), cur_sum(0);
    for(register int i = 1; i <= n; ++i){
        if(a[i] > max_sm) return false;
        if(cur_sum + a[i] > max_sm){
            cur_sum = 0;
            ++subarr_count;
        }
        cur_sum += a[i];
    }
    subarr_count += (cur_sum > 0);
    return subarr_count <= k;
}
 
signed main(){
	SPEED;
	cin >> n >> k;
	int sm(0);
	for(register int i = 1; i <= n; ++i){
        cin >> a[i], sm += a[i];
	}
	int l{1}, r{sm}, mid, best;
	while(l <= r){
        mid = l + ((r - l) >> 1);
        if(check(mid)){
            best = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
	}
	cout << best << '\n';
	return 0;
}