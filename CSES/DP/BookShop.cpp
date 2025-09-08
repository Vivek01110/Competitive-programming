#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int solve(int i ,int maxprice, vector<int>&prices , vector<int>&book, vector<vector<int>>&dp){
    if(i >= prices.size() || maxprice <= 0)
        return 0;

    if(dp[i][maxprice] != -1)
        return dp[i][maxprice];
    
        int take = 0;
    if(prices[i] <= maxprice){
          take = book[i] + solve(i + 1 , maxprice - prices[i] , prices , book, dp);
    }
    int nottake = solve(i + 1 , maxprice, prices , book,dp);

    return dp[i][maxprice] = max(take , nottake);
      
}
int solve(int maxprice, vector<int>&prices , vector<int>&book){
    int n = prices.size();
    vector<int>dp(n,0);
    
    for(int item = 0; item < n; item++){
            for(int mxp = 0; mxp <= maxprice; mxp++){
                 int take = INT_MIN;
                 if(prices[item] <= mxp){
                    take = prices[item] + dp[i - 1];
                 }
            }
    }

    if(prices[i] <= maxprice){
          take = book[i] + solve(i + 1 , maxprice - prices[i] , prices , book, dp);
    }
    int nottake = solve(i + 1 , maxprice, prices , book,dp);

    return dp[i][maxprice] = max(take , nottake);
      
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int>prices(n);
    vector<int>book(n);

    for(int i = 0; i < n; i++) cin >> prices[i];
    for(int i = 0; i < n; i++) cin >> book[i];

    vector<vector<int> >dp(n,vector<int>(x + 1 , -1));

    cout << solve(0,x, prices , book, dp);
 
}
