#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n);

    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    vector<vector<int>>dp(n, vector<int> (n,0));

    dp[0][0] = (grid[0][0] == '.') ? 1 : 0;


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '.'){
                if(j > 0 && grid[i][j - 1] == '.'){
                    dp[i][j] +=  dp[i][j - 1] % MOD;
                }
                if(i > 0 && grid[i - 1][j] == '.'){
                    dp[i][j] +=  dp[i - 1][j] % MOD;
                }
        }
        }

    }

    cout << dp[n - 1][n - 1]% MOD;

}