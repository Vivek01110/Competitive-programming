#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n, k;
        cin >> n >> k;

        vector <ll> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin() , a.end());
        
       
        
        ll sum = 0;
        for(int i = 2*k; i < n; i++){
            sum += a[i];
        }
        ll s = 2*k - 1;
        ll e = n - 1;
        ll maxsum = sum;
        while(s > 0){
            sum += (a[s] + a[s - 1]);
            sum -= a[e];

            maxsum = max(maxsum , sum);

            s -= 2;
            e -= 1;
        }
        
        cout << maxsum << endl;
        
    }
}