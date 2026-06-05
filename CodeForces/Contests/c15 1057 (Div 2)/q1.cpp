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
        set<int> st;
        for(int i =0; i <n; i++){
            int b;
            cin >> b;
            st.insert(b);
        }    
        
        cout << st.size() << endl;
    }
}