#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007


/*int solveBottom( int x ,  vector<int> &prices ,  vector<int> &pages){
    int n = prices.size();
    
    vector<vector<int>> dp(n , vector<int>(x + 1 , -1));

     
    for(int xi = 0; xi <=  x; xi++){
        if(prices[n - 1] <= xi){
            dp[n - 1][xi] = pages[n - 1]; 
        }
        else{
            dp[n - 1][xi] = 0;
        }
        
    } 
    for(int i = n - 2; i >= 0; i--){
        for(int xi = 0; xi <= x; xi++){
           
        
            int ans = 0;
            if(xi - prices[i] >= 0)
                ans = max(ans , pages[i] + dp[i + 1][xi - prices[i]]);

            ans = max(dp[i + 1][xi], ans);

            dp[i][xi] = ans;
        }
    }
    int ans = 0;
    for(int xi = 0; xi <= x; xi++){
        ans = max(ans , dp[0][xi]);
    }

    return ans;
}
*/

/* its giving runtime error because of space complexity

ll bottom(ll x , vector<ll>&pages,vector<ll>&price){
    ll n = pages.size();
    vector<vector<ll>>dp(n + 1,  vector<ll>(x + 1 , 0));
    
    // dp[0][k] = 0; // 0 elements // 1 indexing

    for(int i = 1; i <= n; i++){
        for(int am = 0; am <= x; am++){
            if(am >= price[i - 1]){
                dp[i][am] = max(dp[i][am] , pages[i - 1] + dp[i - 1][am - price[i - 1]]);
            }

            dp[i][am] = max(dp[i][am] , dp[i - 1][am]);
        }
    }

    return dp[n][x];

}
*/


// solution with information
// common mistake :
//  solved correctly which is , you dont take max when u r not taking particaluar elm or (am < price[i])

ll bottom(ll x , vector<ll>&pages,vector<ll>&price){
    ll n = pages.size();
    vector<ll>prev(x + 1 , 0);

/*  SPace optimization
        instead of using two vectors (prev , curr) we can use only one vector because not picking case will be stored in prev and we just update prev by prev[am] = max(prev[am], pages[i] + prev[am - price[i]])

        it will look like 
        dp[am] = max(dp[am], pages[i] + dp[am - price[i]]);
*/

    for(int i = 0; i < n; i++){
        vector<ll>curr(x + 1 , 0);
        for(int am = 0; am <= x; am++){
                if(am >= price[i]){
                    curr[am] = max(curr[am] , pages[i] + prev[am - price[i]]);
                }

                curr[am] = max(curr[am] , prev[am]); 
                // yaha pe bhi likhna hoga kyuki jb (am < price[i]) hoga to nottake wala answer hoga broo
             
        }

        prev = curr;
    }

    return prev[x];

}

/*
int solveBottom( int x ,  vector<int> &prices ,  vector<int> &pages){
    int n = prices.size();
    
    vector<int> dp(x + 1 , 0);

    for(int i = 0; i < n; i++){
        for(int j = x; j >= prices[i]; j--){ 
            dp[j] = max(dp[j], pages[i] + dp[j  - prices[i]]);
        }
    }

    return dp[x];

}
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        ll n , x;
        cin >> n >> x;

        vector<ll> prices(n) , pages(n);

        for(int i = 0; i < n; i++){
            cin >> prices[i];
        }

        for(int i = 0; i < n; i++){
            cin >> pages[i];
        }

 

        cout << bottom(x , pages,prices);
   
}


/* Correct but TLE // recursive

int solve(int i , int x ,  vector<int> &prices ,  vector<int> &pages,  vector<vector<int>> &dp){
    if(i >= prices.size()) return 0;

    if(dp[i][x] != -1) return dp[i][x];
    int take = 0;
    if(x - prices[i] >= 0)
        take = pages[i] + solve(i + 1, x - prices[i] , prices , pages, dp);

    int nottake = solve(i + 1, x, prices , pages, dp);

    return dp[i][x] = max(take , nottake);
}
*/





































// #include<bits/stdc++.h>
// using namespace std;
// #define MOD 1000000007
// int solve(int i ,int maxprice, vector<int>&prices , vector<int>&book, vector<vector<int>>&dp){
//     if(i >= prices.size() || maxprice <= 0)
//         return 0;

//     if(dp[i][maxprice] != -1)
//         return dp[i][maxprice];
    
//         int take = 0;
//     if(prices[i] <= maxprice){
//           take = book[i] + solve(i + 1 , maxprice - prices[i] , prices , book, dp);
//     }
//     int nottake = solve(i + 1 , maxprice, prices , book,dp);

//     return dp[i][maxprice] = max(take , nottake);
      
// }
// int solve(int maxprice, vector<int>&prices , vector<int>&book){
//     int n = prices.size();
//     vector<int>dp(n,0);
    
//     for(int item = 0; item < n; item++){
//             for(int mxp = 0; mxp <= maxprice; mxp++){
//                  int take = INT_MIN;
//                  if(prices[item] <= mxp){
//                     take = prices[item] + dp[i - 1];
//                  }
//             }
//     }

//     if(prices[i] <= maxprice){
//           take = book[i] + solve(i + 1 , maxprice - prices[i] , prices , book, dp);
//     }
//     int nottake = solve(i + 1 , maxprice, prices , book,dp);

//     return dp[i][maxprice] = max(take , nottake);
      
// }
// int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);

//     int n, x;
//     cin >> n >> x;

//     vector<int>prices(n);
//     vector<int>book(n);

//     for(int i = 0; i < n; i++) cin >> prices[i];
//     for(int i = 0; i < n; i++) cin >> book[i];

//     vector<vector<int> >dp(n,vector<int>(x + 1 , -1));

//     cout << solve(0,x, prices , book, dp);
 
// }
