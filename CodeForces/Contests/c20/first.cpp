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
        vector<int>a;
        int len = 1;
        if(n %2 == 0){
            for(int i = 1; i <= n; i += 2){
                a.push_back(len);
                a.push_back(n - len + 1);
                len++;
            }
        }
        else{
            for(int i = 1; i < n; i += 2){
                a.push_back(len);
                a.push_back(n - len + 1);
                len++;
            }

            a.push_back(((n + 1)/2));
        }

        
        reverse(a.begin(), a.end());

        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }

        cout << endl;
    }
}