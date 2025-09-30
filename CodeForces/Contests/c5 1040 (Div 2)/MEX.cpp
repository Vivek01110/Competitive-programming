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

        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        for(int i = 1; i < n - 1; i++){
            if(a[i - 1] == 0 || a[i] == 0 || a[i + 1] == 0){
                cout << "NO" << endl;
                break;
            }
            else{
                // check can we make all three same
                if(a[i - 1] != -1a[i - 1] != a[i] && a[i] != a[i + 1] && a[i - 1] != a[i + 1]){
                    cout << "NO" << endl;
                    break;
                }
            }

        }
    }

}