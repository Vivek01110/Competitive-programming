#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
bool can(vector<ll>&a , int x , ll h){
    ll total = 0;
    for(int i = 0; i < a.size(); i++){
        total += (((h - a[i]) > 0) ? (h - a[i]) : 0);
    }
    
    return total <= x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n,x;
        cin >> n >> x;

        vector<ll> a(n);

        for(int i=  0; i < n; i++) cin >> a[i];

        ll s = 0;
        ll e = INT_MAX;
        ll ans = 0;
        while(s <= e){
            ll mid = s + (e - s)/2;

            if(can(a, x ,mid)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        cout << ans << endl;

    }
}