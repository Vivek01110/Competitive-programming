#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll  window_min(vector<ll>&arr ,ll k){
    int n = arr.size();
    long long mini = 0;
    ll xorr = 0;

    deque<int> dq;

    for(int i = 0; i < n; i++){
        
        if(!dq.empty() && dq.front() <= i - k){ // not in window
           dq.pop_front();
        }

        while(!dq.empty() && arr[dq.back()] >= arr[i]) //  if elm is mini then back of dq
            dq.pop_back();

        dq.push_back(i);

        if(i >= k - 1){
            xorr ^= arr[dq.front()];
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

    cout << window_min(arr  , k);
}