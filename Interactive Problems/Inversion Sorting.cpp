#include "bits/stdc++.h"
using namespace std;
 
signed main(){
    int n = (cin >> n, n);
    cout << "1 1" << endl;
    int pre = (cin >> pre, pre);
    
    vector<int> inv(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cout << "1 " << i << endl;
        int cur1 = (cin >> cur1, cur1);
        int C = i * (i - 1) >> 1;
        inv[i] = (C - (cur1 - pre)) >> 1;

        cout << "1 " << i << endl;
        int cur2 = (cin >> cur2, cur2); // maybe
    }

    vector<int> b(n + 1, 0);
    b[1] = inv[1];
    for(int i = 2; i <= n; ++i) b[i] = inv[i] - inv[i - 1];

    vector<bool> vis(n + 1, false);
    vector<int> a(n + 1, 0);
    for(int x = 1; x <= n; ++x){
        int c(0);
        for(int j = n; j >= 1; --j){
            if(vis[j]) continue;
            int cnt(0);
            for(int k = 1; k < j; ++k){
                if(vis[k]) ++cnt;
            }
            if(b[j] + cnt == j - 1){
                c = j;
                break;
            }
        }
        if(!c){
            for(int j = 1; j <= n; ++j){
                if(!vis[j]){
                    c = j;
                    break;
                }
            }
        }
        vis[c] = true;
        a[c] = x;
    }

    vector<int> cur(n + 1);
    for(int i = 1; i <= n; ++i){
        cur[i] = a[i];
    }

    vector<pair<int, int>> op;
    for(int i = n; i >= 1; --i){
        int j(0);
        for(int idx = 1; idx <= i; ++idx){
            if(cur[idx] == i){
                j = idx;
                break;
            }
        }
        if(j == i) continue;
        if(j ^ 1){
            op.emplace_back(1, j);
            reverse(cur.begin() + 1, cur.begin() + j + 1);
        }
        op.emplace_back(1, i);
        reverse(cur.begin() + 1, cur.begin() + i + 1);
    }

    for(auto o : op){
        cout << o.first << ' ' << o.second << endl;
        int inv_cnt = (cin >> inv_cnt, inv_cnt);
        if(!inv_cnt){
            break;
        }
    }

    return 0;
}