#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    long long  move = 0;

    for(int i = 0; i < n - 1; i++){
        if(v[i] > v[i + 1]){
            move += (long long)v[i] - v[i + 1];
            v[i + 1] += v[i] - v[i + 1];
        }
    }
    cout << move;
}

/*

5
3 2 5 1 7
5
5 4 3 2 1
6
1 2 3 4 5 6
5
1 1 1 1 1
10
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1
10
1000000000 1 1 1 1 1 1 1 1 1
*/