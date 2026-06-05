#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    multiset<int>st;
    
    int cnt = 1;
    for(int i= 0; i < n; i++){
        int elm;
        cin >> elm;

        
         if(!st.empty()){
            auto temp = st.upper_bound(elm); // search tower on top of it can be placed

            if(temp == st.end()){
                cnt++;
            }
            else{
                st.erase(temp); // it will remove only one occurence
            }
        }
        st.insert(elm);
    }

    cout << cnt << endl;

}



// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     vector<pair<int , int>> a(n);

//     for(int i= 0; i < n; i++){
//         cin >> a[i].first;
//         a[i].second = i;
//     }

//     sort(a.begin(),a.end());
//     int cnt =1;
//     for(int i = n - 1; i > 0; i--){
//         if(a[i].second > a[i - 1].second){
//             cnt++;
//         }
//     }

//     cout << cnt << endl;

// }