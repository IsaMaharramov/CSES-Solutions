#include "bits/stdc++.h"
using namespace std;
 
signed main(){
    int n = (cin >> n, n);
    map<int, string> col;
    cout << "? 1" << endl;
    cin >> col[1];
    cout << "? " << n << endl;
    cin >> col[n];
    if(col[1] == col[n]) return cout << "! " << n << endl, 0;
    int l(1), r(n);
    while(r - l > 1){
        int mid = l + ((r - l) >> 1);
        cout << "? " << mid << endl;
        cin >> col[mid];
        int cnt = mid - l + 1;
        if(((col[l] == col[mid]) and !(cnt & 1)) or ((col[l] != col[mid]) and (cnt & 1))){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << "! " << l << endl;
    return 0;
}