// https://atcoder.jp/contests/dp/tasks/

// we can do it without using leading zeroes beacause we can do ans = ans-1  for number 0
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int dp[10001][101][2];

ll solve(int pos , int sum , int tight, int len, int D, string &digits){
    if(pos == len){
        return sum % D == 0;
    }

    if(dp[pos][sum][tight] != -1){
        return dp[pos][sum][tight];
    }

    int maxDigit = tight ? digits[pos] - '0' : 9;
    ll ans = 0;
    for(int d = 0; d <= maxDigit; d++){
        
        int nextTight = tight && (d == maxDigit);
       

        ans += solve(pos + 1 , (sum + d)%D , nextTight, len, D,digits);
        ans %= MOD;
    }

    return dp[pos][sum][tight] = ans;
}

ll solveBottom(int len , int D  ,string &digits){
    
    memset(dp , 0 , sizeof(dp));

    dp[0][0][1] = 1; //{ pos , tight, 0(sum % D)}

    for(int pos = 0; pos < len; pos++){
         
            for(int sum = 0; sum < D; sum++){

                for(int tight = 0; tight <= 1; tight++){

                ll val = dp[pos][sum][tight];
                if(val == 0) continue;
                
                int maxDigit = tight ? (digits[pos] - '0') : 9;
                ll ans = 0;
                for(int d = 0; d <= maxDigit; d++){
                    
                    int nextTight = tight && (d == maxDigit);
                    int nextsum = (sum + d)%D;

                    dp[pos + 1][nextsum][nextTight] = (dp[pos + 1][nextsum][nextTight] + val)% MOD;
                  
                }
            }
        }
    }

    return (dp[len][0][1] + dp[len][0][0])%MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // sum of digit of number should be divisible by d
    string k;
    int d;

    cin >> k >> d;

    int len = k.size();
    memset(dp , -1 , sizeof(dp));
    // ll ans = solve(0 , 0 , 1, len, d, k);
    ll ans = solveBottom(len, d, k);

    cout << (ans - 1 + MOD)%MOD << endl;

    

}

// we can do it without using leading zeroes beacause we can do ans = ans-1  for number 0
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// int dp[10001][101][2][2];

// ll solve(int pos , int sum , int tight,int leading, int len, int D, string &digits){
//     if(pos == len){
//         return !leading && sum % D == 0;
//     }

//     if(dp[pos][sum][tight][leading] != -1){
//         return dp[pos][sum][tight][leading];
//     }

//     int maxDigit = tight ? digits[pos] - '0' : 9;
//     ll ans = 0;
//     for(int d = 0; d <= maxDigit; d++){
        
//         int nextTight = tight && (d == maxDigit);
//         int nextLeading = leading && (d == 0);

//         ans += solve(pos + 1 , (sum + d)%D , nextTight,nextLeading, len, D,digits);
//         ans %= MOD;
//     }

//     return dp[pos][sum][tight][leading] = ans;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     // sum of digit of number should be divisible by d
//     string k;
//     int d;

//     cin >> k >> d;

//     int len = k.size();
//     memset(dp , -1 , sizeof(dp));

//     cout << solve(0 , 0 , 1,1, len, d, k) << endl;

    

// }