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
        ll n;
        cin >> n;
        n--;
        ll msb = log2(n);

        ll num = pow(2 , msb) - 1;
        vector<ll> ans;
        while(num >= 0){
            ans.push_back(num--);
        }
         num = pow(2 , msb);
        while(num <= n){
            ans.push_back(num++);
        }

        for(auto elm : ans){
            cout << elm <<" ";
        }

        cout << endl;
    }   
}