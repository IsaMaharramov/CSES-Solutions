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
 
signed main(){
    SPEED;
    cin >> n;
    vector<string> gray_code;
    gray_code.eb("");
    for(register int i = 1; i <= n; ++i){
        int szl = (int)gray_code.size();
        for(register int j = szl - 1; j >= 0; --j){
            gray_code.eb(gray_code[j]);
        }
        szl <<= 1;
        for(register int j = 0; j < szl; ++j){
            if(j < (szl >> 1)){
                gray_code[j] = '0' + gray_code[j];
            }else{
                gray_code[j] = '1' + gray_code[j];
            }
        }
    }
    for(register int i = 0; i < (int)gray_code.size(); ++i){
        cout << gray_code[i] << '\n';
    }
    return 0;
}
