#include<bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n, k;
        cin >> n >> k;

        int ans = INT_MAX;
        int evencnt = 0;

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;

            if(temp % 2 == 0){
                evencnt++;
            }
            if(temp % k == 0){
                ans = 0;
                
            }
            
            ans = min(k - temp%k , ans);           
        }

        if(k == 4){
            if(evencnt == 0){
                ans = min(ans , 2);
            }
            else if(evencnt >= 2){
                ans = min(ans , 0);
            }
            else{
                ans = min(ans , 1);
            }
    }

        cout << ans << endl;     
    }

}