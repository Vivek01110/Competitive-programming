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
        int n , k;
        cin >> n >> k;

        string s;
        cin >> s;


        int whites = 0;
        int blacks = 0;
        int mincolor = k;

        for(int i= 0; i < n; i++){
            if(i >= k)
                mincolor = min(mincolor , whites);
                
            if(i >= k && s[i - k] == 'W')
               whites--;
                 
            if(s[i] == 'W') whites++;
            

            
        }
        mincolor = min(mincolor , whites);
        cout << mincolor << endl;
    
    }
}