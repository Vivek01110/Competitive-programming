#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>a(n);

    for(int i= 0; i < n; i++) cin >> a[i];

    map<int , int>mp;
    int prev = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        
        mp[a[i]]++;

         
        while(prev < i && mp[a[i]] > 1){
            if(mp[a[prev]] == 1){
                mp.erase(a[prev]);
            }
            else{
                mp[a[prev]]--;
            }

            prev++;
          
        }

        cnt += (i - prev + 1);
          // for 1 2  1
    }

    cout << cnt << endl;

}