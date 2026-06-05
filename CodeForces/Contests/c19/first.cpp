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
        int n,h , l;
        cin >> n >> h >> l;


        vector<int> a(n);

        for(int i = 0; i< n; i++){
            cin >> a[i];
        }

        int sum =0;

        int cnt = 0;

        for(int i = 0; i < n - 1; i++){
            if(a[i] <= h){
                for(int j = i + 1; j < n; j++){
                    if(a[j] <= l){
                        a[j] = l + 1;
                        cnt++;
                        break;
                    }
                }
            }
            else if(a[i] <= l){
                for(int j = i + 1; j < n; j++){
                    if(a[j] <= h){
                        cnt++;
                        a[j] = h + 1;
                        break;
                        
                    }
                }
            }
        }   
      cout << (sum + cnt) << endl;
    }
}