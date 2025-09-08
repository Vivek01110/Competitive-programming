#include<bits\stdc++.h>
using namespace std;
int bit_to_num(vector<int> bits){
    int n = bits.size();
    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        ans += bits[i]*pow(2,i);
    }
    return ans;
}
vector<int> bits_char(int n){
    vector<int> ans;

    while(n >= 0){
        ans.push_back(n&1);
        n = n >> 1;
    }
    
    reverse(ans.begin(),ans.end());

    return ans; 
}

int next_greater(vector<int> bits){
    
    int n = bits.size();
    int ones = 0;
    for(int i = n - 1 ; i > 0; i--){ 
        
        if(bits[i] == 1 && bits[i-1] == 0){
            bits[i] = 0;
            bits[i-1] = 1;

            i++;
            while(i < n - ones){
                bits[i] = 0;
            }

            while(i < n){
                bits[i] = 1;
            }

            break;
            
        }
        if(bits[i] == 1) ones++;
    }

        
    return bit_to_num(bits);
    }

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<int>  bits = bits_char(n);

        cout<<next_greater(bits) << endl;
    }
}