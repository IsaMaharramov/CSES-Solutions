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
    if(n == 1){
        cout << n << ' ';
        exit(0);
    }
    if(n <= 3){
        puts("NO SOLUTION");
        exit(0);
    }
    if(n == 4){
        cout << "2 4 1 3 \n";
        exit(0);
    }
    for(int i = 1; i <= n; i += 2){
        cout << i << ' ';
    }
    for(int i = 2; i <= n; i += 2){
        cout << i << ' ';
    }
    exit(0);
}