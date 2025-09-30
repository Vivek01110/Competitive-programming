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
        ll n , m , x, y;
        cin >> n >> m >> x >> y;

        vector<ll> a(n) , b(m);
        
        for(int i= 0; i < n; i++){
            cin >> a[i];
        }

        for(int i = 0; i < m; i++){
            cin >> b[i];  
        }

        cout << (ll)(n + m) << endl;

       

        
        
    }
}