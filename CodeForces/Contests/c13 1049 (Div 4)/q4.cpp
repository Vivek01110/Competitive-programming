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

        vector<ll> a(n);
        vector<int>odd;
        ll even = 0;

        for(int i= 0; i < n; i++){
            cin >> a[i];

            if((a[i]&1)) odd.push_back(a[i]);
            else{
                even += a[i];
            }

        }

        sort(odd.begin() , odd.end());

         
        ll ans = 0;
        int size = odd.size();
        for(int i= size - 1; i >= size/2; i--){
            ans += odd[i]; 
        }

        if(size > 0) ans += even;
        cout << ans <<endl;

         
    }
}