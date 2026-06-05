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
        int n, k;
        cin >> n >> k;

        vector<long long>a(n), b(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        long long maxb = 0;
        long long prefsum = 0;
        long long maxans = 0;
         
        for(int i = 0; i < n && i < k; i++){

            maxb = max(maxb , b[i]);
            prefsum += a[i];
       
            maxans = max(maxans , prefsum + (maxb*(k - i - 1)));
        }

         cout << maxans << endl;
    }
}