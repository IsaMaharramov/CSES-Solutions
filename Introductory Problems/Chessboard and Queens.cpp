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
 
 
signed main(){
    SPEED;
    string row;
    vector<vector<bool>> blocked(8, vector<bool>(8));
    for(register int i = 0; i < 8; ++i){
        cin >> row;
        for(register int j = 0; j < 8; ++j){
            blocked[i][j] = row[j] == '*';
        }
    }
    vector<int> queens(8);
 
    iota(all(queens), 0);
 
    int valid_num(0);
 
    do{
        bool flag = true;
        for(register int i = 0; i < 8; ++i){
            if(blocked[queens[i]][i]){
                flag = false;
                break;
            }
        }
        vector<bool> taken_d(17);
		for(register int i = 0; i < 8; ++i){
			if (taken_d[i + queens[i]]) {
				flag = false;
				break;
			}
			taken_d[i + queens[i]] = true;
		}
        taken_d = vector<bool>(17);
		for(register int i = 0; i < 8; i++){
			if (taken_d[queens[i] - i + 8 - 1]) {
				flag = false;
				break;
			}
			taken_d[queens[i] - i + 8 - 1] = true;
		}
        valid_num += flag;
 
    }while(next_permutation(all(queens)));
    cout << valid_num << '\n';
    return 0;
}