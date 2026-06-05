#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int>a(n);
    
    for(int i= 0; i < n; i++) cin >> a[i];

    long long maxsum = LONG_LONG_MIN;
    long long sum = 0;

    for(int i=  0; i < n; i++){
        sum += a[i];

        maxsum = max(maxsum , sum);

        if(sum < 0){
            sum = 0;
        }
    }

    cout << maxsum ;

}