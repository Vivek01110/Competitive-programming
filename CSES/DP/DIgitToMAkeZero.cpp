#include<bits/stdc++.h>
using namespace std;

// int solve(int n ,vector<int> &dp){
//     if(n <= 0) return 0;
//     if(dp[n] != -1)
//         return dp[n];
//     int temp = n;
//     int cnt = INT_MAX;
//     while(temp){
//         int digit = temp%10;
//         if(digit > 0)
//             cnt = min(cnt ,1 + solve(n - digit,dp));
//         temp /= 10;    
//     }

//     return dp[n] = cnt;
// }
int solve_Bottom(int n ){
    
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(int  i = 1; i <= n; i++){
        int temp = i;
        while(temp){
            int digit = temp%10;
            if(digit > 0 && i - digit >= 0)
                dp[i] = min(dp[i - digit] + 1 , dp[i]);
            temp /= 10;    
        }

        
    }
    return dp[n];
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);

    cout << solve_Bottom(n);

}