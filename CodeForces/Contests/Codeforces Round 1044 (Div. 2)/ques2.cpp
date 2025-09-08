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
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        sort(a.begin() , a.end());

        ll amerald = 0;
        for(int i = n - 1; i > 0; ){
            amerald += max(a[i] , a[i - 1]);
            a[i] -= a[i - 1];
            a[i - 1] = 0;
            i -= 2;
        }

        if(n&1) amerald += a[0];

        cout << amerald << endl;
    
    }
}