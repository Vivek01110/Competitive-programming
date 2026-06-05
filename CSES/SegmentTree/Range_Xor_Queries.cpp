#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
void build(int i , int l , int r , vector<int>&a , vector<ll>&tree){
    if(l == r){
        tree[i] = a[l];
        return;
    }

    int mid  = (l + r)/2;

    build(2*i + 1 , l , mid , a , tree);
    build(2*i + 2, mid + 1, r , a , tree);

    tree[i] = (tree[2*i + 1]^tree[2*i + 2]);
}


int query(int i , int l , int r , int ql , int qr , vector<ll>&tree){
    if(r < ql || l > qr)
        return 0;

    // complete overlap
    if(ql <= l && r <= qr){
        return tree[i];
    }

    // partial overlap
    int mid = (l + r)/2;

    int leftsum = query(2*i + 1 , l , mid , ql , qr , tree);
    int rightsum = query(2*i + 2 , mid + 1 , r , ql , qr , tree);

    return leftsum^rightsum;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;

    vector<int>a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> tree(4*n , 0);

    build(0, 0 , n - 1, a, tree);

    for(int i = 0; i < q; i++){
        int l , r;
        cin >> l >> r;
        l--; r--; // convert to 0 indexing

        cout << query(0 , 0 , n - 1 , l , r, tree) << endl;
    }
}