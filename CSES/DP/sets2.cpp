#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    long long sum = n*(n + 1)/2;

    if(sum & 1){
        cout << 0;
    }
    else{
        long long target = sum/2;

        vector<long long>dp(target + 1 , 0);

        dp[0] = 1;

        for(int elm = 1; elm <= n; elm++){
            for(int t = target; t >= 1; t--){
            
                if(t - elm >= 0){
                    dp[t] += dp[t - elm];
                    dp[t] %= MOD;
                }
            }
            
        }

        ll inv2 = 500000004;

        cout << (dp[target] * inv2) % MOD;
    }
}