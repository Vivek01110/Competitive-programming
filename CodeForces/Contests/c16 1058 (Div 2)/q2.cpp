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
        vector<ll> b(n) , a(n);
        for(int i = 0; i < n; i++){
            cin >> b[i]
        }
        ll curr = 1;
         
        for(int i = 0; i < n; i++){
            if(b[i] == (i + 1)*i/2){
                a[i] = curr + 1;
            }
        }
    }
}