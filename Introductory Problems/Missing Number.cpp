#include<iostream>
#include<vector>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
int main(){
    fast_io;
    ll n;
    cin >> n;
    ll answer = n * (n + 1) / 2;
    for(int i = 1, a; i < n; ++i){
        cin >> a;
            answer -= a;
    }
    cout << answer << '\n';
    exit(0);
}