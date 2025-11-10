#include "bits/stdc++.h"
using namespace std;
 
signed main(){
    int n = (cin >> n, n);
    vector<int> res(n, 0);
    for(int k = 0; k < 10; ++k){
        string x = "";
        for(int i = 1; i <= n; ++i) x += ((i & (1 << k)) ? '1' : '0');
        cout << "? " << x << endl;
        string y;
        cin >> y;
        for(int i = 0; i < n; ++i) if(y[i] ^ '0') res[i] |= (1 << k);
    }
    cout << "! ";
    for(int i = 0; i < n; ++i) cout << res[i] << ' ';
    cout << endl;
    return 0;
}