 #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
// lower bound
//  static bool cmp(pair<ll , int>&a , int val){
//     return a.first <= val;
// }

 static bool cmp(int val, pair<ll , int>&a){
    return val < a.first;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a(n),b(n),p(n);

    for(int i =0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
    }

    vector<pair<ll , int>>arr(n);

    for(int i = 0; i < n; i++) arr[i] = {a[i], i};

    sort(arr.begin(), arr.end());
    
    vector<ll>dp(n + 1 , 0);
    dp[n]  = 0;
    for(int i = n - 1; i >= 0; i--){
        
        int realindex = arr[i].second;
        ll currend = b[realindex];
        int nextindex = upper_bound(arr.begin(), arr.end(), currend, cmp) - arr.begin();

        dp[i] = max(dp[i + 1], p[realindex] + dp[nextindex]);
    }

    cout << dp[0] << endl;
}