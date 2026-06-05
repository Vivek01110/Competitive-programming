#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >>n;

    vector<int>a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    int maxlen = 1;
    map<int , int>mp;
    int prev = 0;
    for(int i = 0; i < n; i++){
        mp[a[i]]++;

        while(prev <= i && mp.size() != (i - prev + 1)){
            if(mp[a[prev]] > 1){
                mp[a[prev]]--;
            }
            else{
                mp.erase(a[prev]);
            }
            prev++;
        }
        maxlen = max(maxlen , i - prev + 1);
    }
    cout << maxlen << endl;
}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007

// TLE
// bool isposs(int len , vector<int> &a){
//     if(len == 1)
//         return true;
//     int n = a.size();
//     unordered_map<int , int>mp;
//     for(int i = 0; i < n; i++){
//         mp[a[i]]++;

//         if(i >= len){
//             if(mp[a[i - len]] == 1)
//                 mp.erase(a[i - len]);
//             else
//                 mp[a[i - len]]--;
//         }

        

//         if(i >= len - 1){
//             if(mp.size() == len)
//                 return true;
//         } 
//     }

//     return false;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >>n;

//     vector<int>a(n);

//     for(int i = 0; i < n; i++) cin >> a[i];

//     // binary search

//     int s = 1;
//     int e = n;
//     int maxlen = 1;

//     while(s <= e){
//         int mid = s + (e - s)/2;

//         if(isposs(mid , a)){
//             maxlen = mid;
//             s = mid + 1;
//         }
//         else{
//             e = mid - 1;
//         }
//     }

//     cout << maxlen << endl;

// }


// it will fail on this testcase
// 2 3 4 5 2 10 9 8 6 => exp op = 9 it gives 6 cuz of (2)
//     int n;
//     cin >>n;

//     set<int>st;
//     int prev = 1;
//    int maxlen = 1;
//     for(int i = 1; i <=  n; i++){
//         int elm;
//         cin >> elm;

//         st.insert(elm);

//         if((i - prev + 1) != st.size()){
//             prev = i;
//             st.clear();
//             st.insert(elm);
//         }

//         maxlen = max(maxlen , i - prev + 1);
//     }

//     cout << maxlen << endl;