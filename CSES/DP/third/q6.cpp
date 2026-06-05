#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<char >> grid(n, vector<char>(n , 0));
    for(int i= 0;  i< n; i++){
        for(int j =0; j < n; j++){
            cin >> grid[i][j];
        }
        
    }

    
    vector<vector<long long >> dp(n, vector<long long>(n , 0));

    
    if(grid[0][0] == '.') dp[0][0] = 1;

    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '*') continue;
            
                if(i > 0)
                dp[i][j] = (dp[i][j]%MOD + dp[i - 1][j]%MOD) %MOD;
            

                if(j > 0)
                dp[i][j] = (dp[i][j]%MOD + dp[i][j - 1]%MOD) %MOD;
            
            
        }
    }

    cout << dp[n - 1][n - 1];
}