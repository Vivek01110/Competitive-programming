#include<bits/stdc++.h>

using namespace std;

int main(){
    int  n , m , a;
    cin >> n >> m >> a;

    cout << (long long)((long long)ceil((double)n/a)*((long long)ceil((double)m/a)));
}

// Testcasees

/*

6 6 4
8 8 4
1 1 3

1000000000 100000000 1
1000000000 1000000000 1


*/