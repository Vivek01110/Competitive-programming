#include<bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    
    
        int n, x;
        cin >> n >> x;

        vector<int> a(n);

        for(int i= 0; i < n; i++) cin >> a[i];

        vector<int> dp(x + 1 , INT_MAX);

        dp[0] = 0;

        for(int s = 1; s <= x; s++){
            for(int c : a){
                if(s - c >= 0 && dp[s - c] != INT_MAX){
                    dp[s] = min(dp[s] , 1 + dp[s - c]);
                }
            }
        }

        cout << (dp[x] != INT_MAX ? dp[x] : -1)<< endl;
    }

