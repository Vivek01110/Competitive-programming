#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int T;
    cin >> T;

    while(T--){
        int n , k;
        cin >> n >> k;;

        vector<int> v(n);

        for(int i = 0;  i < n; i++){
            cin>> v[i];
        }

        int init = v[k - 1];

        int prev = init;

        set<int> st;

        for(auto c : v){
            if(c >= init) st.insert(c);
        }

        bool ans = true;
        int prev = init;

        for(auto &x : st){
            if(x - prev > init)
                ans = false;
            prev = x;
        }
        
        cout << (ans ? "yes" : "No") << endl;


    }
}