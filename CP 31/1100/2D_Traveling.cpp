#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll dist(pair<ll , ll> &a , pair<ll , ll>&b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n, k , a, b;
        cin >> n >> k >> a >> b;

        a--;
        b--;

 
        vector<pair<ll, ll>>arr(n);

        for(int i = 0; i < n; i++){ 
            cin >> arr[i].first >> arr[i].second;
        }

        ll mindista = LLONG_MAX;
        ll mindistb = LLONG_MAX;

        for(int i = 0; i < k; i++){
            mindista = min(mindista , dist(arr[i] , arr[a]));
            mindistb = min(mindistb , dist(arr[i] , arr[b]));
        }

        long long ans = dist(arr[a] , arr[b]);
 
        cout << min(ans , mindista + mindistb) << endl;
  
    }
}

