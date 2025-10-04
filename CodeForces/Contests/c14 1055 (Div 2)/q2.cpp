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
        ll n , rk, ck , rd , cd;

        cin >> n >> rk >> ck >>rd >> cd;

        ll ans = -1;

        if(rk < rd){
            ans = max(ans , rd);
        } 
        else if(rk > rd){
            ans = max(ans , n - rd);
        }

        if(ck < cd){
            ans = max(ans , cd);
        }
        else if(ck > cd){
            ans = max(ans , n - cd);
        }

        cout << ans << '\n';
    }
}