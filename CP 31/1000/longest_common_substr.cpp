#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int lcs(string& s1, string& s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        vector<vector<int>>dp(n1 + 1, vector<int> (n2 + 1 , 0));
        int maxans = 0;
        
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxans = max(maxans , dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
            

        }
        return maxans;
    }

     

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        string a,b;
        cin >> a >> b;

        int n1 = a.size();
        int n2 = b.size();

        cout << n1 + n2 - 2*lcs(a, b) << endl ;
    }
}


// int lcs(string& s1, string& s2) {
//         int n1 = s1.size();
//         int n2 = s2.size();
//         int maxans = 0;
//         // time complexity O(n^3);
//         for (int i = 0; i < n1; i++) {
//             for (int j = 0; j < n2; j++) {
//                 int temp1 = i;
//                 int temp2 = j;
//                 int len = 0;

//                 // expand while characters match
//                 while (temp1 < n1 && temp2 < n2 && s1[temp1] == s2[temp2]) {
//                     len++;
//                     temp1++;
//                     temp2++;
//                 }

//                 maxans = max(maxans, len);
//             }
//         }
//         return maxans;
//     }
