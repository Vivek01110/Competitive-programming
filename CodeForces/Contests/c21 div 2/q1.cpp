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
        int n, x, y;
        cin >> n >> x >> y;

        vector<ll>a(n);
        ll opr = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];

            sum += a[i]
        }

        ll opr = 0;

        ll sum = a[n - 1];
        for(int i = 0; i < n - 1; i++){
            ll transfers = a[i]/x;

            sum += (transfers*(y - x));
        }

        cout << sum << endl;





    }
}