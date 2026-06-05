#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> a;

        for(int i = 0; i < n; i++){
            if(s[i] == '1') a.push_back(i);
        }

        if(a.size() == 0){
            cout << ((n + 2)/3) << endl;
        }
        else{
            //starting zeroes
            int cnt = a.size(); // no of ones

            cnt += (a[0] + 1)/3;

            for(int i = 0; i < a.size() - 1; i++){
                cnt += (a[i + 1] - a[i] - 1)/3; // zeroes having both sides one
            }

            cnt += ((n - a.back() - 1) + 1)/3; // end zeroes

            cout << cnt << endl;

        }
    }
}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
     
//     int T;
//     cin >> T;

//     while(T--){
//         int n;
//         cin >> n;

//         string a;
//         cin >> a;

//         if(n == 1 && a[0] == '0'){
//            cout << 1 << endl;
//            continue;
//         }
//         int ones = 0;
//         int lastindex = 0;
//         for(int i= 0; i < n; i++){
//             ones += (a[i] - '0');
//             if(a[i] == '1'){
//                 lastindex = i;
//             }

//         }

//         if(ones == 0){
//             cout << (n/2) << endl;
//             continue;
//         }
//         int zeroes = 0;
//         int left = 0;
//         int right = 0;
//         int cnt = 0;

        
//         while(right <= lastindex){
//             if(a[right] == '1'){
//                  right++;
//                  continue;
//             }

//             left = right;
//             while(right <= lastindex && a[right] == '0') right++;
//             int temp = right - left  ;
            
//             if(left == 0)
//                 cnt += (temp + 2)/3;
//             else
//                 cnt += temp/3;     
//         }
          
//           cnt += ((n - lastindex-1) + 2)/3; 
//             cout << (cnt + ones) << endl;

//     }
// }
    
        
//         int zeroes = 0;
//         int ones = 0;
//         int cnt = 0;
//         int start = -1;
        
//         for(int i = 0; i < n; i++){
//             if(a[i] == '0'){
//                zeroes++;
//             }
//             else{
//                 if(start == -1){
//                     cnt += (zeroes/2);
                      
//                 }
//                 else{
//                     start = 0;
//                     if(zeroes == 3){
//                         cnt += 1;
//                     }
//                     else{
//                         cnt += (zeroes - 2)/2;
//                     }

                   
//                 }

//                  zeroes = 0;
//             }

//         }

//         if(zeroes > 0){
//             cnt += zeroes/2;
//         }   

//         cout << (cnt + ones) << endl;
        
//     }
// }