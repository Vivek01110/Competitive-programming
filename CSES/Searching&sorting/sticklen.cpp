#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll>a(n);

    for(int i= 0 ; i< n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll midcost = 0;
    ll mid = n/2;
    if(n & 1) midcost = a[mid];
    else midcost = a[mid - 1] + (a[mid] - a[mid - 1])/2;
    ll totalcost = 0;
    for(int i= 0; i < n; i++){
        totalcost += abs(midcost - a[i]);
    }

    cout << totalcost;
}