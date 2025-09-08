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
        string s;
        cin >> s;
         

        vector<int> nextfreq(26 , 0);

        for(char ch : s){
            nextfreq[ch - 'a']++;
        }

        int prevdist = 0;
        int nextdis  = 0;

        for(int freq : nextfreq){
            if(freq > 0) nextdis++;
        }

        vector<int> prevfreq(26 , 0);

        int maxans = 1;
        
        for(int i = 0; i < s.size() - 1; i++){
            
            prevfreq[s[i] - 'a']++;
            nextfreq[s[i] - 'a']--;

            if(prevfreq[s[i] - 'a'] == 1){
                prevdist++;
            }

            if(nextfreq[s[i] - 'a'] == 0){
                nextdis--;
            }

            maxans = max(maxans , prevdist + nextdis);
        }
         
        cout << maxans << endl;
    }
}



