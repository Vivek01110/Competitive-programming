#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int maxi = 1e6;
     vector<vector<long long>>dp(1e6 + 1, vector<ll>(2 , 0));

        dp[1][0] = 1;
        dp[1][1] = 1;

        for(int i = 2; i <= maxi; i++){
            dp[i][0] = (2LL* dp[i -1][0]%MOD + dp[i - 1][1]%MOD) % MOD ;  //    horizontal cell trying to extend

            dp[i][1] = (4LL*dp[i - 1][1]%MOD + dp[i - 1][0]%MOD) % MOD;
        }


    int T;
    cin >> T; 
    while(T--){
        int n;
        cin >> n;

        cout << ((dp[n][0]%MOD + dp[n][1] %MOD) %MOD) << endl;

    }
}









