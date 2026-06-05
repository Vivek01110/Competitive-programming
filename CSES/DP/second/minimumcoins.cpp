#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    
        ll n , x;
        cin >> n >> x;

        vector<ll>coins(n);

        for(int i= 0; i < n; i++){
            cin >> coins[i];
        }

        vector<int>dp(x + 1 , INT_MAX);

        dp[0] = 0;

        for(int s = 1;  s <= x; s++){
            for(int j = 0; j < n; j++){
                if(s - coins[j] >= 0 && dp[s - coins[j]] != INT_MAX){
                    dp[s] = min(dp[s] , 1 + dp[s - coins[j]]);
                }
            }
        }

        cout << ((dp[x] == INT_MAX) ? -1 : dp[x]);
}