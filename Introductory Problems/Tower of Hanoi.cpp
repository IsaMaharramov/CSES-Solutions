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
 
inline void Tower_of_Hanoi(int n, int A, int B, int C){
    if(!n) return;
    Tower_of_Hanoi(n - 1, A, C, B);
    cout << A << ' ' << C << '\n';
    Tower_of_Hanoi(n - 1, B, A, C);
    return;
}
 
signed main(){
    SPEED;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    Tower_of_Hanoi(n, 1, 2, 3);
    return 0;
}