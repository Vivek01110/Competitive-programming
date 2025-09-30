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
        string a;
        cin >> a;

        int m;
        cin >> m;
        string b;
        cin >> b;

        string c;
        cin >> c;

        for(int i = 0; i < m; i++){
            if(c[i] == 'V'){
                a = b[i] + a;
            }
            else{
                a.push_back(b[i]);
            }
        }

        cout << a << endl;



    }
}