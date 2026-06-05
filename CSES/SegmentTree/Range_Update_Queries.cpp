#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

void build(int i , int l , int r , vector<int>&a , vector<ll>&tree){
    if(l == r){
        tree[i] = a[l];
        return;
    }

    int mid = ( l + r)/2;

    build(2*i + 1 , l , mid , a , tree);
    build(2*i + 2 , mid + 1 , r , a, tree);

    tree[i] = tree[2*i + 1] + tree[2*i + 2];

}

void query(int i , int l , int r , int ql , int qr ,int val, vector<ll>&tree){
    if(r < ql || l > qr)
        return;

    if(ql <= l && r <= qr){
         tree[i] += (ll)(r - l + 1)* (ll)val;
         return;
    }

    int mid = (l + r)/2;

    query(2*i + 1 , l , mid, ql , qr, val, tree);
    query(2*i + 2 , mid + 1 , r , ql ,qr ,val , tree);
}

ll query_update(int i , int l , int r , int pos , vector<int>&a , vector<ll>&tree){
    if(l == r){
       return tree[i];
    }

    int mid = (l + r)/2;

    if(pos <= mid){
        return query_update(2*i + 1 , l , mid , pos  , a , tree);
    }
    else{
        return query_update(2*i + 2 , mid + 1 , r , pos , a , tree);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int>a(n);

    for(int i= 0; i < n; i++) cin >> a[i];

    vector<ll> tree(4*n , 0);
    build(0 , 0 , n -1 , a , tree);

    for(int i = 0; i < q; i++){
        int t , ql , qr;
        cin >> t >> ql >> qr;

        if(t == 1){
            int pos = ql - 1;
            int val = qr;
            query_update(0, 0, n - 1 ,pos , val , a , tree);
        }
        else{
            cout << query(0 , 0, n - 1 , ql - 1 , qr - 1 , tree) << endl;
        }
    }
}