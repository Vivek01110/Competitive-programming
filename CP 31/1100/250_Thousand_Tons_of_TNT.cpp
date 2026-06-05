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
        int n;
        cin >> n;

        vector<ll>a(n);

        for(int i= 0; i < n; i++) cin >> a[i];

      
        vector<long long> pref(n);
        pref[0] = a[0];
        for(int i = 1; i < n; i++){
            pref[i] = (a[i] + pref[i - 1]);
        }

        long long ans = 0;
        for(int k = 1; k <= n/2; k++){
            if(n % k != 0) continue;
            int index = k - 1;
            long long mini = LONG_LONG_MAX;
            long long maxi = 0;
            for(int cnt = 0; cnt < n / k; cnt++){
                long long temp = (index == k - 1) ? pref[index] : pref[index] - pref[index - k];

                mini = min(mini , temp);
                maxi = max(maxi , temp);

                index += k;
            }

            ans = max(ans , maxi - mini);
        }

        cout << ans << endl;
    }
}