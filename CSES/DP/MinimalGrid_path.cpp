#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
// string solve(int i , int j, int n, vector<string>&grid){
//     if(i == n || j == n){
//         return "";
//     }

//     string ans = "";
//     ans = min(ans , (grid[i][j] + solve(i + 1, j, n , grid)));
//     ans = min(ans , (grid[i][j] + solve(i , j + 1 , n , grid)));

//     return ans;
// }

string solveBottom(vector<string>&grid){
    int n = grid.size();
    vector<vector<int>> dp(n  , vector<int>(n));
    dp[n - 1][n - 1] = 0;

    for(int i = 2*n - 2; i >= 0; i--){
        
        // vector<pair<pair<char, int>, pair<int , int>>>diagonal;
        //  {{ch , minchildrank} , {r ,c}}

        vector<pair<int , int>>diagonal;
        // compressed {ch , minchildrank} => compressed (ch - 'A')*10000 + minchildrank


        for(int j = 0; j <= i; j++){
            
            int x = j;
            int y = i - j;

            if(x < 0 || x >= n || y < 0 || y >= n)
                continue;
             
            char ch = grid[x][y];

            int bestrank = 2*n;
            // we are taking childrens rank, in case if same element in diagonal so elm can be sorted beased on its children rank
            if(x + 1 < n) bestrank = min(bestrank , dp[x + 1][y]);
            if(y + 1 < n) bestrank = min(bestrank , dp[x][y + 1]);
            int compval = (ch - 'a')*10000 + bestrank;

            diagonal.push_back({compval , x});
        }

        sort(diagonal.begin(),diagonal.end());

        for(int j = 0; j < diagonal.size(); j++){
            int x = diagonal[j].second;
            int y = i - x;

            dp[x][y] = j; // giving rank to that diogonal
        }
    }

    string ans = "";

    int r = 0;
    int c = 0;


    while(r !=  n - 1 || c != n - 1){
        ans += grid[r][c];
        int rightrank = INT_MAX;
        int downrank = INT_MAX;

        if(r + 1 < n){
            downrank = dp[r + 1][c];
        }

        if(c + 1 < n){
            rightrank = dp[r][c + 1];
        }

        if(rightrank < downrank){
            c++;
        }
        else{
            r++;
        }
    }

    ans += grid[n-1][n-1];

    return ans; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string>grid(n);

    for(int i = 0; i < n; i++) cin >> grid[i];

    cout << solveBottom(grid);
}