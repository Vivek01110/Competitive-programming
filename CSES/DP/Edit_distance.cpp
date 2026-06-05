// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string a, b;

//     cin >> a >> b;

//     int m = a.size();
//     int n = b.size();

//     vector<vector<int>>dp(m +1 , vector<int>(n + 1 , 10000));


//     for(int i= 0; i <= m; i++){
//         dp[i][0] = i;
//     }

//     for(int i = 0; i <= n; i++){
//         dp[0][i] = i;
//     }

//     for(int i= 1; i <= m; i++){
//         for(int j = 1; j <= n; j++){
//             if(a[i - 1] == b[j - 1]){
//                 dp[i][j] = min(dp[i][j] , dp[i - 1][j - 1]);
//             }
//             else{
//                 dp[i][j] = min({dp[i][j] , dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});

//                 // replace
//                 // dp[i][j] = dp[i - 1][j - 1] + 1 after replacing oneo fthe string both character will be same hence they will be discarded from both string , both string length will be decreased by one
//             } 
//         }
//     }

//     cout << dp[m][n] << endl;


// }



#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;

    cin >> a >> b;

    int m = a.size();
    int n = b.size();

    // vector<vector<int>>dp(m +1 , vector<int>(n + 1 , 10000));
    vector<int>prev(n + 1, 10000);
    vector<int>curr(n + 1, 10000);
    
    

    for(int i= 0; i <= n; i++){
        prev[i] = i;
    }

    for(int i= 1; i <= m; i++){
        curr[0] = i;
        for(int j = 1; j <= n; j++){
            if(a[i - 1] == b[j - 1]){
                curr[j] = prev[j - 1];
            }
            else{
                curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});

                // replace
                // dp[i][j] = dp[i - 1][j - 1] + 1 after replacing oneo fthe string both character will be same hence they will be discarded from both string , both string length will be decreased by one
            } 
        }
        prev = curr;
    }

    cout << curr[n] << endl;


}

















// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// int solveBottom(string a , string b){
//     int n = a.size();
//     int m = b.size();
//     int minilen = min(n , m);

//     vector<vector<int>>dp(minilen + 1, vector<int> (minilen + 1 , 0));

//     for(int i= 1; i <= minilen; i++){
//         for(int j = 1; j <= minilen; j++){
//             if(a[i - 1] == b[j - 1]){
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             }
//             else{
//                 dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
//             }
//         }
//     }

//     return dp[minilen][minilen];
    
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string a, b;
//     cin >> a >> b;

//     int lcs = solveBottom(a , b);
//     int alen = a.size();
//     int blen = b.size();
//     int minlen = min(alen , blen);

//     int diffchar = minlen - lcs;
//     int added = abs(alen - blen);

//     cout << (diffchar + added);
// }