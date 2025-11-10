#include "bits/stdc++.h"
using namespace std;
 
#define int long long
#define all(x) x.begin(), x.end()
 
constexpr int sz = 2e5 + 5;
constexpr int inf = 1e9 + 7;

struct SegTree{
    struct Node{
        int l, r, mid, sm;
        stack<int> upd;
        Node* left;
        Node* right;
    };
 
    Node* root;
 
    vector<int>& arr;
 
    SegTree(vector<int>& a) : arr(a) {
        root = new Node;
        root->l = 0;
        root->r = (int)a.size() - 1;
        root->mid = (((int)a.size() - 1) >> 1);
        build(root);
    }
 
    void build(Node* node){
        if(node->l == node->r){
            node->sm = arr[node->l];
            node->upd.push(node->sm);
            return;
        }
 
        node->left = new Node;
        node->left->l = node->l;
        node->left->r = node->mid;
        node->left->mid = ((node->l + node->mid) >> 1);
        build(node->left);
 
 
 
        node->right = new Node;
        node->right->l = node->mid + 1;
        node->right->r = node->r;
        node->right->mid = ((node->mid + 1 + node->r) >> 1);
        build(node->right);
 
        node->sm = node->left->sm + node->right->sm;
 
        return;
    }
 
    void update(Node* node, int &i, int &x){
        if(node->l == node->r){
            node->sm = x;
            node->upd.push(x);
            return;
        }
        if(i <= node->mid){
            update(node->left, i, x);
        }else{
            update(node->right, i, x);
        }
        node->sm = node->left->sm + node->right->sm;
        return;
    }
 
    void update(int i, int x){
        update(root, i, x);
    }
 
    void rollback(Node* node, int i){
        if(node->l == node->r){
            node->upd.pop();
            node->sm = node->upd.top();
            return;
        }
 
        if(i <= node->mid){
            rollback(node->left, i);
        }else{
            rollback(node->right, i);
        }
 
        node->sm = node->left->sm + node->right->sm;
        return;
    }
 
    void rollback(int i){
        rollback(root, i);
    }
 
 
    int query(Node* node, int l, int r){
        if(node->l == l and node->r == r) return node->sm;
        int ans = 0ll;
        if(l <= node->mid){
            ans += query(node->left, l, min(r, node->mid));
        }
        if(node->mid < r){
            ans += query(node->right, max(l, node->mid + 1), r);
        }
        return ans;
    }
 
    int query(int l, int r){
        return query(root, l, r);
    }
 
};
 
 
struct Tree{        /// Thanks -> Axel Magana Falcon (https://codeforces.com/profile/Maaxle)
    int type = -1;
    int a, b, i;
    Tree* next;
    Tree* alt;
};
 
Tree* root = new Tree;
vector<Tree*> nxt = {root};
int n, q;
vector<pair<int, int>> ans;  
 
void add_update(int k, int a, int x){
    nxt[k]->a = a;
    nxt[k]->b = x;
    nxt[k]->type = 0;
    nxt[k]->next = new Tree;
    nxt[k] = nxt[k]->next;
}
 
void add_query(int k, int a, int b, int i){
    nxt[k]->a = a;
    nxt[k]->b = b;
    nxt[k]->i = i;
    nxt[k]->type = 1;
    nxt[k]->next = new Tree;
    nxt[k] = nxt[k]->next;
}
 
void add_copy(int &k){
    nxt[k]->type = 2;
    nxt[k]->alt = new Tree;
    nxt.push_back(nxt[k]->alt);
    nxt[k]->next = new Tree;
    nxt[k] = nxt[k]->next;
}
 
void explore(Tree* tr, SegTree& st){
    if(tr->type == 0){
        st.update(tr->a, tr->b);
        if(tr->next) explore(tr->next, st);
        st.rollback(tr->a);
    }else if(tr->type == 1){
        ans.push_back({tr->i, st.query(tr->a, tr->b)});
        if(tr->next) explore(tr->next, st);
    }else if(tr->type == 2){
        explore(tr->alt, st);
        if(tr->next) explore(tr->next, st);
    }
    return;
}
 
void solve(){
    cin >> n >> q;
    vector<int> t(n);
    for(int &j : t) cin >> j;
    SegTree st(t);
    register int type, i(0), k, a, b, x;
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> k >> a >> x;
            add_update(k - 1, a - 1, x);
        }else if(type == 2){
            cin >> k >> a >> b;
            add_query(k - 1, a - 1, b - 1, i++);
        }else{
            cin >> k;
            --k;
            add_copy(k);
        }
    }
 
    explore(root, st);
 
    sort(all(ans));
 
    for(pair<int, int>& it : ans){
        cout << it.second << '\n';
    }
 
    return;
}
 
signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int TT{1};
    //cin >> TT;
    while(TT--) solve();
    return 0;
}