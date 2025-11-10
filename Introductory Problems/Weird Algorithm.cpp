#include<iostream>
#include<vector>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
int main(){
    fast_io;
    ll n;
    cin >> n;
    cout << n << ' ';
    while(n > 1){
        if(n%2){
            n = 3 * n + 1;
        }else{
            n = (n >> 1LL);
        }
        cout << n << ' ';
    }
    exit(0);
}