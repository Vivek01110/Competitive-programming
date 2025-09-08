#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    // WRong Answer  // pretests failed
    while(T--){
        int n, r, b; 
        cin >> n >> r >> b;
        
        int cons_r = r/(b+1);
        // int rem_r = b == 1 ? (r % (b + 1)) : r%b;
        int rem_r = r % (b + 1);
        string withrem;
        for(int i = 0; i <= cons_r; i++)
            withrem += 'R';  

        string notrem;
        for(int i = 0; i < cons_r; i++)
            notrem += 'R';  

        
         
        string ans;
        int i = 0;
        for(; i < rem_r; i++){
            ans += (withrem + 'B');
        }


        for(; i < b; i++)
            ans += (notrem + 'B');

        ans += notrem;


        cout << ans << endl;

    }
}