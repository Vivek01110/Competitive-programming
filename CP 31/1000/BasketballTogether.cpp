#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   
        int n, d;
        cin >> n >> d;

        vector<int > a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        sort(a.begin() , a.end());

        int s = 0;
        int e = n - 1; 

        int wins = 0;
        while(s <= e){
           
            int power = a[e];
            while(s < e && power <= d){
                power += a[e];
                s++;

            }

            if(power > d){
                wins++;
            }
            e--;
        }

        cout << wins << endl;
    }
