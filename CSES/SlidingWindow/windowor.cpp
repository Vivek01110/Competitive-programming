#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll  window_xor(vector<ll>&arr ,ll k){
    int n = arr.size();
   
    vector<int>cnt(30 , 0);
    vector<int>windxor(30 , 0);

     
    for(int i = 0; i < n; i++){
        int temp = arr[i];

        for(int j = 0; j < 30 && temp; j++){
            cnt[j] += (temp&1);
            temp = temp >> 1;
        }

        if(i >= k){
            temp = arr[i - k];

            for(int j = 0; j < 30 && temp; j++){
                cnt[j] -= (temp&1);
                temp = temp >> 1;
            }

        }

        if(i >= k - 1){
           
            // xor with current window
            for(int j = 0; j < 30; j++){
                if(cnt[j] >= 1){
                   windxor[j] = windxor[j]^1;
                }
                else{
                    windxor[j] ^= 0;
                }
            }
            
        }

    }

        int num = binary_to_num(windxor);

        return num;
    }

   



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n , k;
    cin >> n >> k;

    long x , a ,b ,c;
    cin >> x >> a >> b >> c;

    vector<long long> arr(n);

    arr[0] = x;

    for(int i = 1; i < n; i++){
        arr[i] = ((ll)a*arr[i - 1] + b)%c;
    }

    cout << window_xor(arr  , k);
}