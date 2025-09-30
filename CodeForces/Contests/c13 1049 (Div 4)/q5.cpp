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

        vector<int> k(n);
        vector<vector<int>>a(n);

        for(int i= 0; i < n; i++){
            cin >> k[i];
        }
        
        for(int i = 0; i < n; i++){
            vector<int> arr(k[i]);
            for(int j = 0; j < k[i]; j++){
                cin >> arr[j];
            }

            a[i] = arr;
        }

       




        

        
    }
}