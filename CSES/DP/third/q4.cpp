#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
long long solve(int n , int x , vector<int>&coins){
    if(x < 0) return 0;
    if(x == 0) return 1;
    long long cnt = 0;
    for(int j = 0; j < n; j++){
        cnt += (solve(n , x - coins[j], coins));
        cnt %= MOD;
    }

    return cnt;
}

long long solveBottom(int n , int x , vector<int>&coins){
    if(x < 0) return 0;
    if(x == 0) return 1;
    long long cnt = 0;
    vector<ll> dp(x + 1 , 0);
    dp[0] = 1;
    for(int j = 0; j < n; j++){
        for(int s = 0; s <= x; s++)
    
        if(s - coins[j] >= 0){
            dp[s] += (dp[s - coins[j]]);
            dp[s] %= MOD;
        }
    }

    return dp[x];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin >> n >> x;

    vector<int>coins(n);

    for(int i= 0; i < n; i++){
        cin >> coins[i];
    }

    // long long ans = solve(n , x , coins);
    long long ans = solveBottom(n , x , coins);

    cout << ans;
}