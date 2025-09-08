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
        ll n;
        cin >> n;
        vector<ll> v;
        ll itr = 1;
        for(int k = 1; k <= 18; k++){
            itr *= 10;
            ll p = itr + 1;
            if(p > n) break;
            if(n%p == 0){
                 v.push_back(n/p);
            }
        }
        
        if(v.size() == 0){
            cout << 0 << endl;
        }
        else{
            sort(v.begin() , v.end());
            cout << v.size() << endl;
            for(ll x : v){
                cout << x << " ";
            }

            cout << endl;
        }
    }
}


            
            // vector<int> ans;
            // // it will add 11
            // cout << (num.substr(0 , num.size()/2 + 1)) << " ";


            // if(num.size() == 18){
            //     bool flag = true;

            //     string nonzero = start + start + start + "";
            //     cout << nonzero << endl;
            //     // start 0...3
            //     for(int i = 0; i < num.size() - 3; i++){
            //          cout << nonzero  << "000";
            //     }

            //     cout << " ";
            // }

            // for(int i = 0; i < num.size()/2 - 1; i++){
            //     cout << start;
            //     cout << "0" << endl;
            // }

            
        // if(flag == false || num.size()&1){
        //     cout << 0;
           
        // }
        // else{

        //     cout << stoi(num.substr(0 , num.size()/2 + 1));

        //     if(num.size() == 18){

        //         string ans;
        //         int i = 0;
        //         while(i < 5){
        //             ans += start + start + start + "000";
        //             i++;
        //         }

        //         ans += start + start + start;

        //         cout << stoi(ans);
        //     }
        //     if(num.size() == 8){

        //         string ans;
        //         int i = 0;
        //         while(i < 4){
        //             ans += start + start + "00";
        //             i++;
        //         }

        //         ans += start + start;

        //         cout << stoi(ans);
        //     }
            
        //     if(num.size() == 4){

        //         string ans;
        //         int i = 0;
        //         while(i < 3){
        //             ans += start + "00";
        //             i++;
        //         }

        //         ans += start;

        //         cout << stoi(ans);
        //     }




        // }

        // cout << endl;



