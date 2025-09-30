#include<bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        if(n == 2){
            cout << -1 << " " << 2 << endl;
            continue;
        }
        else{
            for(int i = 1; i <= n; i++){
                if(i % 2 == 1) cout << -1 << " ";
                else{
                    if(i == n) cout << 2;
                    else cout << 3 << " ";
                }
                
            }

            cout << endl;
        }
        
    }

}