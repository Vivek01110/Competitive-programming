#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll dp[20][11][2][2];

ll solve(int pos , int prevd,  int tight , int leading , int len,vector<int>&digits){
    if(pos == len) return 1;

    if(dp[pos][prevd][tight][leading] != -1)
        return dp[pos][prevd][tight][leading];
    

    int maxDigit = tight ? digits[pos] : 9;

    ll ans = 0;
    for(int d = 0; d <= maxDigit; d++){

        if(prevd == d) 
            continue;

        int nextTight = tight && (d == maxDigit);
        int nextLeading = leading && (d == 0);

        int nextprevd = 10;
        if(!nextLeading){ // 0001 // if curr pos is 3rd 0 then prevd = 10
            nextprevd = d;
        }

        ans += solve(pos + 1 , nextprevd, nextTight,nextLeading, len , digits);
    }

    return dp[pos][prevd][tight][leading] = ans;

}
ll count(ll x){
    if(x < 0) return 0;

    vector<int> digits;
    if(x == 0) digits.push_back(0);

    while(x){
        digits.push_back(x%10);
        x /= 10;
    } 

    reverse(digits.begin(), digits.end());

    int len = digits.size();
    memset(dp, -1 , sizeof(dp));

    return solve(0, 10,1,1,len,digits);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;

    

    cout << (count(b) - count(a - 1)) << endl;

    




   
    

    


    

    

    

}



// MY code, not working for some testcase
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// ll dp[20][10][2][2];
// ll solve(int pos , int prevd, int tight_start, int tight_end, int len , vector<int>&start_num,vector<int>&end_num){
//     if(pos == len){
//         return 1;
//     }

//     if(dp[pos][prevd][tight_start][tight_end] != -1){
//         return dp[pos][prevd][tight_start][tight_end];
//     }
    
//     int minDigit = tight_start ? start_num[pos] : 0;
//     int maxDigit = tight_end ? end_num[pos] : 9;
    
//     ll ans = 0;
//     for(int d = minDigit; d <= maxDigit; d++){ 
        
//         // wrong here
//         if(prevd == d) continue; // if a = 51 , b = 1242 so it will not count 0052
       
//         int next_tight_start = tight_start && (d == minDigit);
//         int next_tight_end = tight_end && (d == maxDigit);

//         ans += solve(pos + 1 , d , next_tight_start,next_tight_end,len , start_num, end_num);

//     }

//     return dp[pos][prevd][tight_start][tight_end] = ans;

    
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ll a, b;
//     cin >> a >> b;

//     ll len = to_string(b).size();

//     vector<int>start_num(len, 0);
//     vector<int>end_num(len, 0);

//     int i = len - 1;
//     ll temp = a;
//     while(temp > 0){
//         start_num[i--] = temp%10;
//         temp /= (ll)10;
//     }

//     temp= b;
//     i = len - 1;
//     while(temp > 0){
//         end_num[i--] = temp%10;
//         temp /= (ll)10;
//     }

//     memset(dp, -1, sizeof(dp));
    
//     ll ans = 0;
//     for(int d = start_num[0]; d <= end_num[0]; d++){
        
//         if(d == end_num[0] && d == start_num[0]){
//             ans += solve(1, d, 1, 1, len , start_num,end_num);
//         }
//         else if(d == end_num[0]){
//             ans += solve(1, d, 0, 1, len , start_num,end_num);
//         }
//         else if(d == start_num[0]){
//             ans += solve(1, d, 1, 0, len , start_num,end_num);
//         }
//         else{
//             ans += solve(1, d ,0,0,len , start_num,end_num);
//         }
         
//     }

//     cout << ans << endl;
// }