#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
// int solve(int i , int j , int n , int m , vector<int> &a , vector<int>&b){
//     if(i == n || j == m){
//         return 0;
//     }
//     int ans = 0;
//     if(a[i] == b[j]){
//         ans = 1 + solve(i + 1 , j + 1 , n , m , a , b);
//     }
//     else{
//         ans = max({ans ,solve(i + 1 , j , n , m , a, b), solve(i , j + 1 , n , m, a, b)});
//     }

//     return ans;
// }

void solveBottom(vector<int>&a , vector<int>&b){
    int n = a.size();
    int m = b.size();

    vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , 0));

    

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }


    }

    cout << dp[n][m] << endl;

    int r = n;
    int c = m;
    vector<int>seq;
    
    while(r > 0 && c > 0){

        if(a[r - 1] == b[c - 1]){
            seq.push_back(a[r - 1]);
            r--;
            c--;
        }
        else if(dp[r - 1][c] >= dp[r][c - 1]){
            r--;
        }
        else{
            c--;
        }
    }

    

    reverse(seq.begin(),seq.end());

    for(int i= 0; i < seq.size(); i++){
        cout << seq[i];

        if(i != (seq.size() - 1)){
            cout << ' ';
        }
    }

    

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int>a(n) , b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    // cout << solve(0, 0, n, m ,a,b) << endl;
    solveBottom(a,b);


}