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
        int n, k;
        cin >> n >> k;

       string a;
       cin >> a;

        

        int len = 0;
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(a[i] == '1') len++;
             
            if(len >= k) flag = false; 

            if(a[i] == '0') len = 0;
            
        }

        if(flag == false){
            cout << "NO" << endl;
        }
        else{
            vector<int> ans(n);
            int num = 1;
            int maxnum = n;
            for(int i = 0; i < n; i++){
                if(a[i] == '1') ans[i] = num++;
                else ans[i] = maxnum--;
            }
            cout << "YES" << endl;
            for(int i= 0; i < n; i++){
                cout << ans[i] << " ";
            }

            cout << endl;
            
        }

        
}
}