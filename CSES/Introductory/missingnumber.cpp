#include<bits/stdc++.h> 

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n - 1; i++){
        cin >> v[i];
    }

    int xorr = 0;

    for(int i = 0; i < n; i++){
        xorr ^= v[i];
    }

    for(int i = 1; i <= n; i++){
        xorr ^= i;
    }

    cout << xorr;

}