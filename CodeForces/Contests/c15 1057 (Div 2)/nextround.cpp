#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
        int n, k;
        cin >> n >> k;

        vector<int>a(n);

        for(int i =0; i < n; i++){
            cin >> a[i];
        }

      
        int cnt = 0;

        int kthelm = a[k - 1];

        for(int i= 0; i < n; i++){
            if(a[i] > 0 && a[i] >= kthelm){
                cnt++;
            }
        }

        cout << cnt << endl;
    }
