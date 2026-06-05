#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

bool ispall(int n){
    
    string s;
    while (n > 0) {
        s.push_back((n & 1) + '0');   
        n >>= 1;
    }
    string t = s;
    reverse(t.begin(), t.end());
    int size = s.size();
     
    
    return s == t;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        int num = n;

        
           bool odd = (n % 2 != 0) && ispall(n);
           bool even = (n % 2 == 0) && ispall(n/2);

        if(n == 0 || odd || even){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}