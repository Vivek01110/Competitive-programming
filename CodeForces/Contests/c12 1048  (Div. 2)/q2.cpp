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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
       
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        
        sort(a.begin() , a.end());

        ll ans = 0;
        ll i = n - 1;
        while(i >= 0 && m > 0){
            ans += ((ll)a[i]*m);
            m--;
            i--;
        }

        cout << ans << endl;


        
    }
}