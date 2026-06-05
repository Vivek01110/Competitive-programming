#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int>a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int>dp(n, 1);
    
  
    int maxi = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
             if(a[i] > a[j]){
                dp[i] = max(dp[i], 1 + dp[j]);
             } 
        }

        maxi = max(dp[i], maxi);
    }

    cout << maxi << endl;
}