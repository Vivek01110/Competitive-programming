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

        string  s;
        cin >> s;
        int openings = 0;
        int closing = 0;
        int opr = 0;
        for(int i= 0; i < n; i++){
            if(s[i] == ')') closing++;
            else openings++;

            if(openings < closing){
                openings++;
                opr++;
            } 
        }

        cout << opr << endl;
    }
}