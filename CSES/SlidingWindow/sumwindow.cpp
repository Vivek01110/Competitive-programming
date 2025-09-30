#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll  window_sum(vector<ll>&arr ,ll k){
    int n = arr.size();
    long long sum = 0;
    ll xorr = 0;
    for(int i = 0; i < n; i++){
        sum += (ll)arr[i];
        if(i >= k){
            sum -= arr[i - k];
        }

        if(i >= k - 1){
            xorr ^= sum;
        }
    }
    return xorr;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n , k;
    cin >> n >> k;

    long x , a ,b ,c;
    cin >> x >> a >> b >> c;

    vector<long long> arr(n);

    arr[0] = x;

    for(int i = 1; i < n; i++){
        arr[i] = ((ll)a*arr[i - 1] + b)%c;
    }

    cout << window_sum(arr  , k);
}