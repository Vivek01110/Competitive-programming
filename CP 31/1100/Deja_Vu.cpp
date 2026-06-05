#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n, q;
        cin >> n >> q;

        vector<ll>a(n) ,x(q);

        for(int i = 0; i < n; i++)
            cin >> a[i];
        ll maxi = 1;
        for(int i = 0; i < q; i++){
            cin >> x[i];
            maxi = max(maxi , x[i]);
        }

            
        
        vector<pair<ll , int>>div;  // number , index

        for(int i = 0; i < n; i++){
            if(a[i] == a[i+1]) cin >> a[i];
        }
    }
}