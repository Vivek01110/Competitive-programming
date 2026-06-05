#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll>dp(n + 1 , INT_MAX);
    dp[0] = 0;
    for(ll s = 1; s <= n; s++){
        
        ll temp = s;

        while(temp){
            int digit = temp%10;
            if(digit > 0 && s - digit >= 0){
                dp[s] =  min(dp[s] , 1 + dp[s - digit]);
            }
            

            temp /= 10;
        }
    }

    cout << dp[n];
}