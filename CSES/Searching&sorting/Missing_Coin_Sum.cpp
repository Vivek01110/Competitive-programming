#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    
    
    vector<ll>a(n);
    for(int i =0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    ll s = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > s + 1){
            cout << s + 1 << endl;
            return 0;
        }

        s += a[i];
    }

    cout << s + 1 << endl;

    

    

}