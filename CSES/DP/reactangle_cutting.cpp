#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b;
    cin >> a >>b;

    

    vector<vector<int>>dp(a + 1 , vector<int>(b + 1 , 1e9));
    int len = min(a, b);
    for(int i = 0; i <= len; i++){
            dp[i][i] = 0; 
    }

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            
            // horizontal cut
            for(int k = 1; k < i; k++){
                dp[i][j] =  min(dp[i][j] , 1 + dp[k][j] + dp[i - k][j]);
            }

            // vertical cut
            for(int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }
        }
    }

    cout << dp[a][b];
    
}