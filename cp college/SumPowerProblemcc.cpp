#include<iostream>
#include<string>
using namespace std;

int sum_power(int n , int k , string str){
    int diffrents = 0;
    int power = 0;

    for(int i = 0; i < n - 1; i++){
        
        
        // when the window size is less than k;
        if(str[i] != str[i+1])
            diffrents++;
        
        // when i is greter than k only then we can compare  starting character of window , if both are different then remove from the window
        if(i > k && str[i-k] != str[i - k]){
            diffrents--;
        }
        
        if(i > k){
            power += diffrents;
        }

        

    }

    return power;
    
}
int main(){
    int T;
    cin >> T;

    while(T--){
        
        int n,k;
        cin >> n >> k;

        string str;
        cin >> str;

        cout << sum_power(n,k,str) << endl;
    }
}