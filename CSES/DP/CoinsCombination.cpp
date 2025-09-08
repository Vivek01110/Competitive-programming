#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    
    int n, x;
    cin >> n >> x;

    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    vector<long long >dp(x + 1 , 0);

    dp[0] = 1;

    for(int s = 1; s <= x; s++){
        for(int c : a){
            if(s - c >= 0){
                dp[s] +=  (long long)(dp[s - c])%MOD;
            }
        }
    }

    cout <<dp[x]%MOD<< endl;
}

