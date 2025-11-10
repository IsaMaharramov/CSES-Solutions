#include "bits/stdc++.h"
using namespace std;
 
constexpr int sz = 2e5 + 5;
 
struct BitTrieNode{
  BitTrieNode *child[2];
  int cnt;
  BitTrieNode(){
    child[0] = child[1] = nullptr;
    cnt = 0;
  }
};
 
class BitTrie{
private:
  BitTrieNode *root;
  static const int MAX_BITS = 31;
 
  void freeNode(BitTrieNode *node){
    if(!node) return;
    freeNode(node -> child[0]);
    freeNode(node -> child[1]);
    delete node;
  }
 
  void remove(BitTrieNode *node, int i, int num){
    if(i > MAX_BITS) return;
    int bit = (num >> i) & 1;
    BitTrieNode *child = node -> child[bit];
    if(!child) return;
    remove(child, i + 1, num);
    if(--child -> cnt == 0){
      freeNode(child);
      node -> child[bit] = nullptr;
    }
  }
 
public:
  BitTrie(){ root = new BitTrieNode(); }
 
  ~BitTrie(){ freeNode(root); }
 
  void insert(long long num){
    BitTrieNode *node = root;
    for(int i = MAX_BITS; i >= 0; --i){
      int bit = (num >> i) & 1;
      if(!node -> child[bit]) node -> child[bit] = new BitTrieNode();
      node = node -> child[bit];
      node -> cnt++;
    }
  }
 
  void remove(long long num){ remove(root, 0, num); }
 
  long long max_xor(long long num){
    long long res = 0;
    BitTrieNode *node = root;
    for(int i = MAX_BITS; i >= 0; --i){
      int b = (num >> i) & 1;
      int want = b ^ 1;
      if(node -> child[want]){
        res |= (1LL << i);
        node = node -> child[want];
      }else{
        node = node -> child[b];
      }
    }
    return res;
  }
};
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int N = (cin >> N, N);
  vector<int> A(N);
  for(int &j : A) cin >> j;
  vector<int> pref(N + 1, 0);
  for(int i = 0; i < N; ++i){
    pref[i + 1] = pref[i] ^ A[i];
  }
  BitTrie trie;
  trie.insert(0); // pref[0]
  long long mx_xor(0ll);
  for(int j = 1; j <= N; ++j){
    mx_xor = max(mx_xor, trie.max_xor(pref[j]));
    trie.insert(pref[j]);
  }
  cout << mx_xor << '\n';
  return 0;
}