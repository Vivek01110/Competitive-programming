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
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for(ll &i : a) cin >> i;
        
        for(int i=0; i<n; i++) {
            cout << a[i] + 1ll*(a[i]%(k+1))*k << ' ';
    }
    cout << '\n';
    }
}

