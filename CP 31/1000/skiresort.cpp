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
        ll n, k, q;
        cin >> n >> k >> q;

        vector<ll>a(n);

        for(ll i=0; i < n; i++){
            cin >> a[i];

            
        }
        ll len = 0;
        ll cnt = 0;
        for(int i= 0; i < n; i++){
            if(a[i] <= q){
                len++;
            }
            else{
                len = 0;
            }
            // else{
            //     if(len >= k)
            //         // cnt += (((len*(len + 1))/2) - (k*(k - 1)/2));
            //     len = 1;
            // }
            if(len >= k){
                cnt += (len - k + 1);
                
            }

        }
        // if(len >= k){
        //     // cnt += (((len*(len + 1))/2) - (k*(k - 1)/2));
        //     cnt += (len - k + 1);
        // }

        cout << cnt << endl;


    }
}