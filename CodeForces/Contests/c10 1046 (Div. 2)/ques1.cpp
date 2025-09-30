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
        int a , b , c, d; 
        cin >> a >> b >> c >> d;

        c -= a;
        d -= b;
        bool flag = true;
        
        if(a <= b){
             if(b != 0 && ((b + 1)/2) - 1 > a)
                flag = false;
        }
        
        else{
            if(a != 0 && ((a + 1)/2) - 1 > b)
                flag = false;
        }

        if(c <= d){
            if(d != 0 && ((d + 1)/2) - 1 > c)
                flag = false;
        }
        else{
            if(c != 0 && ((c + 1)/2) - 1 > d)
                flag = false;
        }

        if((a == 0 && b >= 3) || b == 0 && a >= 3 || c == 0 && d >= 3 || d == 0 && c >= 3)
            flag = false;

        cout << (flag ? "YES" : "NO") << endl;

        } 
        
        
        
    }