#include<bits/stdc++.h>
using namespace std;


int max_number(int n , int m){
    int max_num = INT_MIN;

    if(n == 0) return -1;
    if(m == 0) return 0;

    vector<int> prefix(n+1,0);

    while(m--){
            int a;
            cin >> a;
            int b;
            cin >> b;

        //if a or b is out of of bound
        if(a < 0  || b > n - 1) return -1;
        // if a is greater than b then swapped the values
        if(a > b){
            swap(a,b);
        }

        prefix[a] = 100;
        prefix[b + 1] = -100;
    }

    max_num = prefix[0];

    for(int i = 1; i < n; i++){
        prefix[i] += prefix[i-1];
        max_num = max(max_num , prefix[i]);
    }

    return max_num;


}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        int m;
        cin >>m;

        cout << max_number(n , m) << endl;

    }


}

/*

T
n 
m
pairs



6

6
2
1 3 3 5
0
23
5
0
4
3
1 2 3 2 1 0
4
2
-1 0 0 3
1
5
3
0 4 3 5 2 4




*/