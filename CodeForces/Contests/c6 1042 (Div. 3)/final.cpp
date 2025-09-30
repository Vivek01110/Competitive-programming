#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int i1 = -1, j1 = -1;
        bool found = false;

        // Step 1: find the first coprime pair
        for (int i = 0; i < n && !found; i++) {
            for (int j = i + 1; j < n; j++) {
                if (gcd(a[i], a[j]) == 1) {
                    i1 = i;
                    j1 = j;
                    found = true;
                    break;
                }
            }
        }

        if (!found) { // No coprime pair exists at all
            cout << 0 << "\n";
            continue;
        }

        // Step 2: find the second coprime pair disjoint from the first
        bool secondFound = false;
        for (int i = 0; i < n && !secondFound; i++) {
            if (i == i1 || i == j1) continue;
            for (int j = i + 1; j < n; j++) {
                if (j == i1 || j == j1) continue;
                if (gcd(a[i], a[j]) == 1) {
                    cout << i1 + 1 << " " << j1 + 1 << " " << i + 1 << " " << j + 1 << "\n";
                    secondFound = true;
                    break;
                }
            }
        }

        if (!secondFound) {
            cout << 0 << "\n";
        }
    }
}

//    int T;
//    cin >> T;

//    while(T--){
//     int n;
//     cin >> n;

//     vector<int>a(n);
    
//     for(int i = 0; i < n; i++) cin >> a[i];


//     bool get = false;
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             for(int k = j + 1; k < n; k++){
//                 for(int l = k + 1; l < n; l++){
//                     if(gcd(a[i],a[j]) == 1 && gcd(a[k] , a[l]) == 1){
//                         cout << i + 1 << " " << j + 1 << " " << k + 1 << " " <<  l + 1 << endl;
//                         get = true;
//                         break;
//                     }

//                     if(get) break;
                        
//                 }
//                 if(get) break;
//             }
//             if(get) break;
//         }
//         if(get) break;
//     }

//     if (get == false) cout << 0 << '\n';

    
// }
// }