#include<iostream>
#include<algorithm>
//#include "bits/stdc++.h"
using namespace std;
 
int n, x[200005], cnt[1000006], ans(1);
 
inline void f(int d){
  for(register int i = 2; i * i <= d; ++i) if(d % i == 0) cnt[d/i] += (cnt[i]++, bool((d / i) ^ i));
  return cnt[d]++, void();
}
 
 
signed main(){
  
  scanf("%d", &n);
 
  for(register int i = 1; i <= n; ++i){
    scanf("%d",&x[i]);
    f(x[i]);
  }
 
  int mx = *max_element(x+1, x+n+1);
 
  for(register int i = mx; i; --i){
    if(cnt[i] > 1){
      ans = i;
      break;
    }
  }
 
  printf("%d\n", ans);
 
}