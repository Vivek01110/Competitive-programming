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

      
        vector<vector<int>>a(n);
        int mini = INT_MAX;
        int smini = INT_MAX;
        long long beauty = 0;
       
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;

            vector<int> temp(m);
            
          
            for(int j = 0; j < m; j++){
                cin >> temp[j];
                mini = min(mini, temp[j]);  
            }
            

            sort(temp.begin() , temp.end());
            smini = min(smini , temp[1]);
            beauty += temp[1];

        } 
        beauty += (ll)mini;
        beauty -= (ll)smini;

        

        cout << beauty << endl;
    }
}