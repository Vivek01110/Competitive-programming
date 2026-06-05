#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    
        ll n , x;
        cin >> n >> x;

        vector<ll>coins(n);

        for(int i= 0; i < n; i++){
            cin >> coins[i];
        }

        vector<int>dp(x + 1 , 0);

        dp[0] = 1;

        for(int j = 0; j < n; j++){
            for(int s =  1; s <= x; s++){
                if(s - coins[j] >= 0){
                    dp[s] += dp[s - coins[j]];
                    dp[s] %= MOD;
                }
            }
        }

        cout << dp[x] << endl;

}