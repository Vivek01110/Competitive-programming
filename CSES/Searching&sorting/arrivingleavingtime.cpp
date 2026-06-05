// approach 2
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int , int>>arr;
    for(int i= 0; i < n; i++){ 
       int a ,b;
       cin >> a >> b;

       arr.push_back({a, 1});
       arr.push_back({b, -1});
    }

    sort(arr.begin(), arr.end());

    int cnt = 0;
    int maxcnt = 0;

    for(int i = 0; i < 2*n; i++){  
        cnt += arr[i].second;
        maxcnt = max(maxcnt, cnt);
    }

    cout << maxcnt;
}


// MY approach first
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;

//     vector<pair<int , int>>a(n);
//     for(int i= 0; i < n; i++){ 
//        cin >> a[i].first >> a[i].second;
//     }

//     sort(a.begin(), a.end());

//     priority_queue<int , vector<int> , greater<int>>pq;
//     pq.push(a[0].second);
   
   
//     int maxcnt = 1;
//     int cnt = 1;
//     int j = 0;
    
//     for(int i = 1; i < n; i++){  
//         cnt++;
//         while(!pq.empty() && pq.top() < a[i].first){
//             cnt--;
//             pq.pop();
//         }

//         maxcnt = max(maxcnt , cnt); 
//         pq.push(a[i].second);
//     }

//     cout << maxcnt;
// }