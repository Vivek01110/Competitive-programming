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

        
        set<ll> st;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++){
            ll temp;
            cin >> temp;

            a[i] = temp;

            st.insert(temp);
        }
        ll maxi = 0;
        for(int elm : a){
            if(st.find(elm - 1) == st.end()){
                
                ll temp = elm;
                while(st.find(temp) != st.end()){
                    temp += 1;
                }

                maxi = max(temp - elm , maxi);

            }
        }

        cout << maxi << endl;

       
    }
}