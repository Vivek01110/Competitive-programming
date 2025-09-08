#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long solve(int n , vector<int> &dp){
    if(n < 0) return 0;
    if(n == 0) return 1;

    if(dp[n] != -1)
        return dp[n];
    long long cnt = 0;
    for(int i = 1; i <= 6; i++){
        cnt += (long long)(solve(n - i , dp));
        cnt %= MOD;
    }

    return dp[n] = cnt;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    
        int n;
        cin >> n;
        vector<int> dp(n + 1 , -1);
        cout << solve(n,dp) << endl;
  

}