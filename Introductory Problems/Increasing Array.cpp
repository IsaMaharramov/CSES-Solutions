#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<math.h>
#define all(v) v.begin(),v.end()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
int main(){
    fast_io;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    ll answer = 0;
    for(int i = 1; i < n; ++i){
            if(a[i] - a[i-1] < 0){
        answer += abs(a[i] - a[i-1]);
        a[i] += abs(a[i] - a[i-1]);
            }
    }
    cout << answer << '\n';
    exit(0);
}