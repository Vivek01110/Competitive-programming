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

        vector <int> a(n);
        
        for(int i= 0; i < n; i++){
            cin >> a[i];
        }
        
        bool flag = false;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] == a[j]){
                    flag = true;
                    break;
                }
            }
        }

        cout << (flag ? "YES" : "NO") << endl;
    }
}