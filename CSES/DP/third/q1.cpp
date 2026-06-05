#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

// long long solve(long long n, vector<ll> &dp){
//     if(n < 0) return 0;
    
//      if(n == 0) return 1;

//      if(dp[n] != - 1)
//         return dp[n];

//      long long cnt = 0;

//      for(int i= 1; i <= 6; i++){
//          cnt = (cnt + solve(n - i, dp))%MOD;
         
//      }

//      return dp[n] = cnt;
// }

long long solveBottom(long long n){
        vector<ll> dp(n + 1 , 0);
     if(n == 0) return 1;

    
    dp[0] = 1;
    long long cnt = 0;
    for(int s = 1; s <= n; s++){
        for(int i= 1; i <= 6; i++){
            if(s - i >= 0){
                dp[s] += (dp[s - i]);
                dp[s] %= MOD;
            }
        }
    }
     

    return dp[n];
}
int main(){

    int n;
    cin >> n;

    // vector<ll> dp(n + 1 , -1);
   
    // cout << solve(n, dp);
    cout << solveBottom(n);



    }

