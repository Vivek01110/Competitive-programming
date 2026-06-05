#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int solve(int n , int x, vector<int>&coins ){
    if(x < 0){
        return INT_MAX;
    }

    if(x == 0){
        return 0;
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int temp = solve(n , x - coins[i] , coins);

        if(temp != INT_MAX){
            ans = min(ans, 1 + temp);
        }
        
    }

    return ans;
}

int solveBottom(int n , int x, vector<int>&coins ){
    if(x < 0){
        return INT_MAX;
    }

    if(x == 0){
        return 0;
    }

    vector<int>dp(x + 1, INT_MAX);
    int ans = INT_MAX;
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX){
                dp[i] = min(dp[i],1 + dp[i - coins[j]]);
            }  
        }
    }
    

    return dp[x];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin >> n >> x;

    vector<int>coins(n , 0);

    for(int i= 0; i < n; i++){
        cin >> coins[i];
    }

    // int ans = solve(n ,x, coins);
    int ans = solveBottom(n ,x, coins);

    cout <<(ans == INT_MAX ? -1 : ans);

    
}