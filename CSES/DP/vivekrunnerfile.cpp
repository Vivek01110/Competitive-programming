#include<bits/stdc++.h>
using namespace std;
int solve(int n ,vector<int> &dp){
    if(n <= 0) return 0;
    if(dp[n] != -1)
        return dp[n];
    int temp = n;
    int cnt = INT_MAX;
    while(temp){
        int digit = n - temp%10;
        if(digit > 0)
            cnt = min(cnt ,1 + solve(n - temp%10,dp));
        temp /= 10;    
    }

    return dp[n] = cnt;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);

    cout << solve(n , dp);

}