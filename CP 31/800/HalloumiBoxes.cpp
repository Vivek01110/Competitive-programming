#include<bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n , k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        if(k > 1)
            cout << "YES" << endl;
        else{
            bool flag = true;
            for(int i = 0; i < n - 1; i++){
                if(a[i] > a[i + 1]){
                    flag = false;
                    break;
                }
            }

            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
         }
    }

}