#include<iostream>
#include<vector>
#include<set>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
int main(){
    fast_io;
    string s;
    cin >> s;
    set<int> st;
    char cur = s[0];
    int pos = 0;
    for(int i = 1; i < (int)s.size(); ++i){
        if(cur != s[i]){
            st.insert(i - pos);
            cur = s[i];
            pos = i;
        }
    }
    st.insert((int)s.size() - pos);
    cout << *st.rbegin() << '\n';
    exit(0);
}