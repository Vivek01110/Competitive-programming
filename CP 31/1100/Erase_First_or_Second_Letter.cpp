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

        string a;
        cin >> a;

        if(n == 0) cout << 0 << endl;
        int ans = 0;
        set<char>st;
        st.insert(a[0]);
        for(int i = 1; i < n; i++){
            ans += st.size();
            st.insert(a[i]);
        }

        ans += st.size();

         

        cout << ans << endl;
    }
}