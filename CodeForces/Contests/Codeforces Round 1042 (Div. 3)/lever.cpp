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

        vector<int>a(n);
        vector<int>b(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        int cnt = 0;
        bool flag = true;

        while(flag){
            flag = false;

            for(int i = 0; i < n; i++){
                if(a[i] > b[i]){
                    a[i]--;
                    flag = true;
                    break;
                }
            }

             for(int i = 0; i < n; i++){
                if(a[i] < b[i]){
                    a[i]++;
                    break;
                    
                }
            }

            cnt++;
        }

        cout << cnt << endl;
    }
}