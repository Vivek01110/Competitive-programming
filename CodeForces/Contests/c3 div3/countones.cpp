#include<bits/stdc++.h>
using namespace std;
int countoness(int n , string &s){
    if(n == 0) return 0;

    int ones = 0;

    for(int i = 0; i < n; i++){
        ones += (s[i] - '0');
    }

    return ones*(ones - 1) + (n - ones)*(ones + 1);
}
int main(){
    int T;
    cin>> T;

    while(T--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        cout << countoness(n , s) << endl;
    }
}
