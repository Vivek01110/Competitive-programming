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
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        s = s + s;
          n = 2*n;
        int g = n;
        int ans = 0;
        
        for(int i = n - 1; i >=0; i--){
            if(s[i] == 'g'){
                g = i;
            }

            if(s[i] == c && g != n){
                ans = max(ans , g - i);
            }

          
        }

        cout << ans << endl;


    }
}