#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
class SegmentTree{
    public:
    vector<ll> tree;
    vector<int>arr;
    int n;

    SegmentTree(int n , vector<int> arr){
        this -> arr = arr;
        this -> n  = n;
        tree.assign(4*n , INT_MAX);
    }
    void build(int i , int l , int r , vector<int>&a , vector<ll>&tree){
        if(l == r){
            tree[i] = a[l];
            return;
        }

        int mid = ( l + r)/2;

        build(2*i + 1 , l , mid , a , tree);
        build(2*i + 2 , mid + 1 , r , a, tree);

        tree[i] = min(tree[2*i + 1] ,tree[2*i + 2]);

    }

    int query(int i , int l , int r , int ql , int qr , vector<ll>&tree){
        if(r < ql || l > qr)
            return INT_MAX;

        if(ql <= l && r <= qr){
            return tree[i];
        }

        int mid = (l + r)/2;

        int left = query(2*i + 1 , l , mid, ql , qr, tree);
        int right = query(2*i + 2 , mid + 1 , r , ql ,qr , tree);

        return min(left , right);
    }

    void query_update(int i , int l , int r , int pos , int val ,   vector<int>&a , vector<ll>&tree){
        if(l == r){
            tree[i] = val;
            a[pos] = val;
            return;
        }

        int mid = (l + r)/2;

        if(pos <= mid){
            query_update(2*i + 1 , l , mid , pos , val , a , tree);
        }
        else{
            query_update(2*i + 2 , mid + 1 , r , pos , val , a , tree);
        }

        tree[i] = min(tree[2*i + 1],tree[2*i + 2]);
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int>a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    
    SegmentTree sg(n,a);

}