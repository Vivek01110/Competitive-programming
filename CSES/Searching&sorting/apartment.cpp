#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll>a(n); // each persons desire size
    vector<int>b(m); // apt size

    for(int i= 0;  i< n; i++) cin >> a[i];
    for(int i= 0; i < m; i++) cin >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(), b.end());

    int i = 0;
    int j = 0;
    int cnt = 0;
    while(i < n && j < m){
        int x = a[i];
        if(x - k <= b[j] && b[j] <= x + k){
            cnt++;
            i++;
            j++;
        }
        else if(b[j] < x - k){
            j++;
        }
        else{
            i++;
        }
    }

    cout << cnt;
    
}