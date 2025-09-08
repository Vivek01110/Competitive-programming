#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
 

      
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        unordered_map<int , int> mp;
        int one = -1;
        int two = -1;
        bool flag = true;

        for(int i = 0; i < n; i++){
            if(mp.find(a[i]) == mp.end()){
                if(one == -1){
                    one = a[i];
                }
                else{
                    two = a[i];
                }
            }

            mp[a[i]]++;

            if(mp.size() > 2){
                flag = false;
                break;
            }

        }

            if(flag == false){
                cout << "No" << endl;     
            }
            else{
                if(one != -1 && two != -1 && abs(mp[one] - mp[two]) > 1){
                    cout << "No" << endl;
                }
                else{
                    cout << "Yes" << endl;
                }
            }

            // cout << one << " " << two << endl;

           

        }
 
        
    }
