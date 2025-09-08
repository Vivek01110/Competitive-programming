#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n,k;
        cin >> n >>  k;

        string s;
        cin >> s;

        unordered_map<int , int > mp;
        
        for(char ch : s){
            mp[ch]++;
        }

        int oddfreq = 0;

        for(auto itr : mp){
            char ch = itr.first;
            int freq = itr.second;

            if(freq % 2 != 0){
                oddfreq++;
            }
        }
        // cout << oddfreq << endl;
        if((k == oddfreq || oddfreq == k + 1) || ((k == 0 && (oddfreq == 0 || oddfreq == 1)) || k && (oddfreq%k == 0 || oddfreq % k == 1))){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

        
    }
}