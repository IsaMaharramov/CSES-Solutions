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
 
const int sz = 2e5 + 5;
 
int n;
int a[sz], p[sz];
 
signed main(){
	SPEED;
	cin >> n;
	for(register int i = 1; i <= n; ++i){
		cin >> a[i];
		int l = i - 1;
		while(a[l] >= a[i]){
			l = p[l];
		}
		p[i] = l;
		cout << p[i] << ' ';
	}
	cout << '\n';
	return 0;
}
