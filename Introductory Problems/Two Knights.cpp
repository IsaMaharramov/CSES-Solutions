#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long k;
    cin>>k;
    for(unsigned long long n=1; n<=k; n++){
    cout<<((n - 1)*(n + 4)/2LL)*(n*n - 3*n + 4)<<'\n';
    }
    return 0;
}