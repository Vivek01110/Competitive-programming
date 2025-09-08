#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;
        

        int zero = 0;
        int ones = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') zero++;
            else ones++;
        }

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') ones--;
            else zero--;

            if(zero < 0 || ones < 0){
               ans = s.size() - i  ;
                break;
            }
                
        }

        cout << ans << endl;

      
    }
}


// int zero = 0;
        // int ones = 0;

      

        // cout << abs(zero - ones) << endl;