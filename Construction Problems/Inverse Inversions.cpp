#include "bits/stdc++.h"
using namespace std;
 
constexpr int sz = 1e6 + 6;
 
#define int long long
 
int n, k, ans[sz], top;
 
signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    int cur(0);
    for(register int i = 1; i <= n; ++i){
        int ad = n - i;
        if(cur + ad <= k){
            ans[++top] = (cur += ad, n - i + 1);
        }else{
            int x = k - cur + 1;
            ans[++top] = x;
            for(int i = 1; top < n; ++i){
                if(i ^ x) ans[++top] = i;
            }
            break;
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << ans[i] << " \n"[i == n];
    }
}
/*
 
x - 1 = k - cur
x = k - cur + 1
 
 
*/