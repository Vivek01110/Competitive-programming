#include<bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    int T;
    cin >> T;

     while(T--){
        int n , k , q;
        cin >> n >> k >> q;

        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];

            if(a[i] > q) a[i] = 0;
            else a[i] = 1;
        }

        int ans = 0;
        int  cnt = 0;
      
        for(int i = 0; i < n; i++){
            if(a[i] == 1){
                cnt++;
            }
            if(a[i] == 0){
                if(cnt >= k)
                    ans += (cnt - k + 1)*(cnt - k + 2)/2;
                cnt = 0;  
            } 
        }
        if(cnt >= k)
                ans += (cnt - k + 1)*(cnt - k + 2)/2;
 

        cout << ans << endl;
     }

}