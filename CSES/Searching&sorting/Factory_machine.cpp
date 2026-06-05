#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
bool isposs(ll time , ll remprod , vector<ll>&a){
    
    for(int i = 0; i < a.size(); i++){
        remprod -= (time/a[i]);

        if(remprod <= 0) break;
    }

    return remprod <= 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,t;
    cin >> n >> t;

    vector<ll> a(n);

    for(ll &elm : a) cin >> elm;
    sort(a.begin(), a.end());

    ll s = 1;
    ll e = 1e18;
    
    while(s < e){
        ll mid = s + (e - s)/2;

        if(isposs(mid ,t,  a)){
            e = mid;
        }
        else{
            s = mid + 1;
        }
    }

    cout << s << endl;
    



    

}