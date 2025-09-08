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
        int n ,x;
        cin >> n >> x;

        vector<ll> a(n);

        for(int i= 0; i < n; i++){
            cin >> a[i];
        }

        ll ans = 0;
        ll l1 = a[0] - x; 
        ll r1  = a[0] + x;

        // intersection formula {max(l1 , l2) , min(r1 , r2)}
        for(int i = 1; i < n; i++){
            ll l2 = a[i] - x;
            ll r2 = a[i] + x;
            
             l1 = max(l1 , l2);
             r1 = min(r1 , r2);

             if(l1 > r1){
                ans++;
                l1 = l2;
                r1 = r2;
            }    
        } 

        cout << ans << endl;


    }
}