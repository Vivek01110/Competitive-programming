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
        int n , m;
        cin >> n >> m;
        bool iszero = false;
        ll sum = 0;
        int neg = 0;
        int mini = 100;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int num; 
                cin >> num;
                sum += abs(num);

                if(num < 0) neg++;
                else if(num == 0){
                    iszero = true;
                }
                
                if(num != 0){  
                    mini = min(mini , abs(num));
                }

                
            }
        }

        if(iszero || (neg%2 == 0)){
            cout << sum << endl;
        }
        else if(neg&1){
            sum -= 2*mini;
            cout << sum << endl;
        }
        
    }
}