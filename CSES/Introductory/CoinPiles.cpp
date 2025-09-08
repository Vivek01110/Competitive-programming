#include<iostream> 

using  namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int a , b;
        cin >> a >> b;
        
        // bool ans = true;
        // if((a + b)%3 != 0 || a/2 > 2 || b/2 > a){
        //     ans = false;
        // }
        cout << (((a + b)%3 == 0) && !(a/2 > b || b/2 > a) ? "YES" : "NO") << endl;


    }
}