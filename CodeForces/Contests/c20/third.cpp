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

        vector<int> a(n);
      
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<int> b = a;

        sort(b.begin(), b.end());
        int mini = b[0];
        int maxi = b.back();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            if(b[i] != a[i]){
                ans = min(ans , max(maxi - a[i], a[i]- mini));
            }
        }

        cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
}