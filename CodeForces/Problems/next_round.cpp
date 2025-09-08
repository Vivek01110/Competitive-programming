#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , k;
    cin >> n >> k;

    vector<int> v(n);
    
    int kthelm = 101;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(k && v[i] < kthelm){
            kthelm = v[i];
            k--;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        
        if(v[i] >= kthelm){
            cnt++;
        }
    }

    cout << cnt ;
    

    


}

/*
8 5
10 9 8 7 7 7 5 5

7 5
10 8 6 4 4 2 0

4 2
0 0 0 0

*/