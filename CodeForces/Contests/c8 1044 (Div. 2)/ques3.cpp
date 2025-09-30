#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> h(n);
        for(int i=0; i<n; i++) cin >> h[i];

        ll ans = LLONG_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, h[i] + (long long)(n - i - 1));
        }
        cout << ans << "\n";
    }
}
