#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
long long bfs(int x , int k){
    long long c = pow(2, k);
    long long v = pow(2, k);

    queue<pair<int , vector<int>>>q; //{c ,v , mincnt , path}

  

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int  k , x; 
        cin >> k >> x;

        if(k == x){
            cout << 0 << endl << endl;
        }
        else{
            ll mincnt = 0;
            vector<int> ans;

            cout <<  bfs(x,k) << endl; 
        }


    }
}