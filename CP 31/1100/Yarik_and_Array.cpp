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

        vector<int>a(n);

        for(int i= 0; i < n; i++) cin >> a[i];

        int maxsum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(i == 0 || ((a[i]&1) == (a[i - 1]&1)))
                sum = a[i];
            else{
                sum += a[i];
            }

            maxsum = max(maxsum , sum);

            if(sum < 0) sum = 0;
        }
        cout << maxsum << endl;
    }
}