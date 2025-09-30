#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll costof(ll x){
    return pow(3 ,x + 1) + x * pow(3 ,x - 1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
  

    while(T--){
        int n;
        cin >> n;
        
        ll cost = 0;

        while(n > 0){
            ll x = log(n)/log(3);

            if(pow(3 ,x + 1) == n){
                x = x + 1;
            }

            cost += costof(x);
            x = pow(3 ,x);
            n = n - x;
        }

        cout << cost << endl;
       
    }
}