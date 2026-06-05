#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
// ll solve(ll sum, vector<ll>&dp){
//     if(sum < 0){
//         return 0;
//     }

//     if(sum == 0) return 1;

//     if(dp[sum] != -1){
//          return dp[sum];
//     }

//     ll cnt = 0;
//     for(ll i = 1; i <= 6; i++){
//         cnt += solve(sum - i,dp);
//         cnt %= MOD;
//     }

//     return dp[sum] = cnt;
    
// }

ll solve(ll sum){
    vector<ll>dp(sum + 1 , 0);
    dp[0] = 1;
    for(int i = 1; i <= sum; i++){
        
        for(int j = 1; j <= 6; j++){
            if(i - j >= 0)
                dp[i] += dp[i - j]%MOD;
                dp[i] %= MOD;
        }
    }

    return dp[sum];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int sum;
    cin >> sum;
    vector<ll>dp(sum + 1 , -1);
     cout << solve(sum) << endl;
}