#include "bits/stdc++.h"
using namespace std;

constexpr int N = 1e5 + 5;
int n, k, F[N], S[N];
bitset<N> F_asked, S_asked;

inline void query_F(int x){
    if(x < 1 or x > n) return;
    if(!F_asked[x]){
        cout << "F " << x << endl;
        cin >> F[x];
        F_asked[x] = 1;
    }
    return;
}

inline void query_S(int x){
    if(x < 1 or x > n) return;
    if(!S_asked[x]){
        cout << "S " << x << endl;
        cin >> S[x];
        S_asked[x] = 1;
    }
    return;
}

signed main(){
    cin >> n >> k;
    int L = max(0, k - n);
    int R = min(n, k);
    int ans = -1;
    while(L <= R){
        int x = (L + R) / 2;
        if(x > 0){
            query_F(x);
            if(x < n) query_F(x + 1);
        }
        if(k - x > 0){
            query_S(k  - x);
            if(k - x < n) query_S(k - x + 1);
        }

        bool flag1 = true;
        if(x >= 1 and k - x + 1 <= n){
            query_F(x);
            query_S(k - x + 1);
            if(F[x] < S[k - x + 1]){
                flag1 = false;
            }
        }

        bool flag2 = true;
        if(k - x >= 1 and x + 1 <= n){
            query_S(k - x);
            query_F(x + 1);
            if(S[k - x] < F[x + 1]){
                flag2 = false;
            }
        }

        if(flag1 and flag2){
            if(!x){
                query_S(k);
                ans = S[k];
            }else if(x == k){
                query_F(k);
                ans = F[k];
            }else{
                query_F(x);
                query_S(k - x);
                ans = min(F[x], S[k - x]);
            }
            break;
        }else if(!flag1){
            R = x - 1;
        }else{
            L = x + 1;
        }
    }

    cout << "! " << ans << endl;

    return 0;
}