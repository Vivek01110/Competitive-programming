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
        int n , k;
        cin >> n >> k;

        string s;
        cin >> s;
        // int ones = 0;
        // int cnt = 0;
        // for(int i= 0; i < n; i++){
        
        //     if(i >= k && s[i - k] == '1') ones--;

        //     if(s[i] == '1' && ones > 0) cnt++;

        //     if(s[i] == '1') ones++;
        // }

        // cout << cnt << endl;
        
         int last = -k; 
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                int pos = i+1; // convert to 1-indexed
                if(pos - last >= k){
                    ans++;
                }
                last = pos;
            }
        }
        cout<<ans<<"\n";

    }
}