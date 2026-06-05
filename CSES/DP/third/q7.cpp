#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
// long long solve(int i , int x , int n , vector<ll>&price , vector<ll>&pages, vector<vector<ll>>&dp){
//     if(x < 0) return 0;
//     if(i == n){
//         return 0;
//     }

//     if(dp[i][x] != -1){
//         return dp[i][x];
//     }

//     int take = 0;
//     int nottake = 0;

//     if(x - price[i] >= 0){
//         take = pages[i] + solve(i +1 , x - price[i], n , price , pages,dp);
//     }

//     nottake = solve(i + 1 , x , n , price , pages,dp);

//     return dp[i][x] = max(take , nottake);
// }

// int solveBottom(int x , vector<ll>&price , vector<ll> &pages){
//     int n = price.size();
//     if(x <= 0) return 0;

//     vector<vector<long long>>dp(n  + 1, vector<ll>(x + 1,  0));

//      dp[0][x] = 0;

//     for(int i = 1; i <= n; i++){
//         for(int am = 0; am <= x; am++){
//             if(am - price[i - 1] >= 0){
//                 dp[i][am] = max(dp[i][am], pages[i - 1] + dp[i - 1][am - price[i -1]]);
//             }

//             dp[i][am] = max(dp[i][am] , dp[i - 1][am]);
//         }
//     }

//     return dp[n][x];
// }

int solveBottom1(int x , vector<ll>&price , vector<ll> &pages){
    int n = price.size();
    if(x <= 0) return 0;

    // vector<long long>prev(x + 1 , 0);
    // vector<long long> curr(x  + 1 , 0);
    vector<long long> dp(x  + 1 , 0);


    

    for(int i = 0; i < n; i++){
        for(int am = x; am >= price[i] ; am--){ // if reverse so it will access prev dp 
                dp[am] = max(dp[am], pages[i] + dp[am - price[i]]);   
        } 
    }

    return dp[x];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin >> n >> x;

    vector<ll>price(n);
    vector<ll>pages(n);

    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> pages[i];

    // vector<vector<ll>> dp(n , vector<ll>(x + 1, -1));

    // cout << solve(0, x ,n, price , pages, dp);
    cout << solveBottom1( x , price , pages);

}