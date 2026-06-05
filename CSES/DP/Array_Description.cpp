#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int solve(int i, int last , int n , int m, vector<int>&a){
    if(i == n){
        return 1;
    }
    int cnt = 0;
    if(i > 0){
        if(a[i] != 0 && abs(last - a[i]) > 1){
            return 0;
        }
        else if(a[i] == 0){
            for(int j = -1; j <= 1; j++){
                cnt += (solve(i + 1 , last + j , n , m , a));
            }
        }
    }
    else if(a[i] == 0){

         for(int j =1 ; j <= m; j++){
             cnt += solve(i + 1 , j ,n , m, a);
         } 
    }

    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << solve(0 ,-1, n , m , a);

    
    
   


}