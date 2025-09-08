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
        int n;
        cin >> n;

        string s;
        cin >> s;
        int empty = 0;
        int minopr = 0;
        bool flag = false;
        for(int i = 0; i < n; i++){
            // empty
            char ch = s[i];
            if(ch == '.') empty++;

            if(empty > 2){
                flag = true;
                break;
            }

            if(ch == '#' || i == n - 1){
                minopr += empty;
                empty = 0;
            }
                
            
        }
        
        if(flag) 
            cout << 2 << endl;
        else
            cout << minopr << endl;
    }
}


    