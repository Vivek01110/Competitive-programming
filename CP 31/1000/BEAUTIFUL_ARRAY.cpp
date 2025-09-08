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
        ll n , k,  b, s; 
        cin >> n >> k >> b >> s;

        ll mini = k*b;
        ll maxi = k*b + n*(k - 1);

        if(mini <= s && s <= maxi){
            vector<ll> ans(n , 0);

            ans[0] = mini;

            s -= mini;

            for(int i = 0; i < n; i++){
                
                ll add = min(k - 1 , s);

                ans[i] += add;
                s -= add;
            }
            
             
            for(int i= 0; i < n; i++){
                cout << ans[i] <<  " ";
            }
            cout << endl;
        }
        else{
            cout << -1 << endl;
        }

        
    }
}