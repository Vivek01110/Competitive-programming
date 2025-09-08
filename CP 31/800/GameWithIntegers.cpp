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

        if(n %3 == 0){
            cout << "Second" <<endl;
        }
        else{
            cout << "First" << endl;
        }
    }
}