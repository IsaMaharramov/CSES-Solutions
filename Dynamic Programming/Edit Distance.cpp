#include<iostream>
#include<vector>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int Levenshtein_distance(string& a, string& b, int n, int m, vector<vector<int>> &memo){
    if(memo[n][m]){
        return memo[n][m];
    }else if(!n or !m){
        return (n + m);
    }else if(a[n - 1] == b[m - 1]){
        return memo[n][m] = Levenshtein_distance(a, b, n - 1, m - 1, memo);
    }else{
        return memo[n][m] = min(Levenshtein_distance(a, b, n, m - 1, memo),min(Levenshtein_distance(a, b, n - 1, m, memo),Levenshtein_distance(a, b, n - 1, m - 1, memo) )) + 1;
    }
}
int main(){///Levenshtein distance
    fast_io;
    string a, b;
    cin >> a >> b;
    int n = (int)a.size();
    int m = (int)b.size();
    vector<vector<int>> memo(n + 1, vector<int> (m + 1,0));
    cout << Levenshtein_distance(a, b, n, m, memo) << '\n';
    exit(0);
}