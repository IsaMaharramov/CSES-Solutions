#include<iostream>
#include<set>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    fast
    int n,a;
    cin>>n;
    set<int> st;
    while(n--){
    cin>>a;
    st.insert(a);}
    cout<<st.size()<<'\n';
    return 0;
}