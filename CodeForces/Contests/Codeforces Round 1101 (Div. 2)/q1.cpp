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

        vector<int> a(n);

        for(int i= 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int i = 0;
        int left = 0;
        int ans = 0;
        while(i < n){
            int j = i;
            while (j < n && a[j] == a[i]) j++;

            int freq = j - i;
            int l = left;
            int r = n - left - freq;

            ans = min(ans, max(l, r));

            left += freq;
            i = j;

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

//         vector<int> a(n);

//         for(int i= 0; i < n; i++)
//             cin >> a[i];

//         sort(a.begin(), a.end());

//         int med = 0;
//         if(n % 2  == 0){
//             bool flag = true;
//            for(int i= 0; i < n; i++){
//                if(a[i] != a[i + 1])
//                     flag = false;
//            }

           
//            cout << (flag ? 0 : n/2) << endl;
         
//         }
//         else{
//             int mid = n/2;
//             int cnt = 0;
//             for(int i =0; i < mid; i++){
//                 if(a[i] != a[mid] || a[n - i] != a[mid]){
//                     cnt++;
//                 }
//             }

//             cout << cnt << endl;
        
        

        

//         }
            
    

        
//     }
// }