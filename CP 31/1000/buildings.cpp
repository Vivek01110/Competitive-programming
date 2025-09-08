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
        vector<int> a(n); // a[i] no if visits of ith building
        vector<pair<int , int>>v(n); // {a[i] , index}
        for(int i = 0; i < n; i++){
            cin >> a[i];
            v[i] = {a[i] , i};
        }
        unordered_map<int , int>mp; //{i , pos}
        sort(v.begin() , v.end());

        for(int i = n - 1; i >= 0; i--){
            
        }

        


        


        
    }
}