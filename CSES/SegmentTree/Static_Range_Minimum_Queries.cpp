#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

void build(int i ,int l , int r , vector<int>&a ,vector<int>&tree){
    if(l == r){
        tree[i] = a[l];
        return;
    }

    int mid = (l + r)/2;

    build(2*i + 1 , l , mid , a , tree);
    build(2*i + 2,  mid + 1 , r, a , tree);

    tree[i] = min(tree[2*i + 1] , tree[2*i + 2]);
}

int query(int i, int l , int r , int ql, int qr , vector<int>&tree){
    if(r < ql || l > qr){
        return INT_MAX;
    }
    // complete overlap
    if(ql <= l && r <= qr){
        return tree[i];
    }

    int mid = (l + r)/2;
    int left = query(2*i + 1 , l, mid , ql ,qr , tree);
    int right = query(2*i + 2 , mid + 1, r , ql ,qr , tree);

    return min(left , right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;

    vector<int>a(n);

    for(int i= 0; i < n; i++) cin >> a[i];

    vector<int>tree(4*n , INT_MAX);

    build(0, 0, n - 1 , a, tree);

    for(int i =0; i < q; i++){
        int l , r;
        cin >> l >> r;
        l--; r--;

        cout << query(0, 0, n - 1, l , r , tree) << endl;
    }
}