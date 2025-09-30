#include<iostream> 
#include<vector>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n , k;
        cin >> n >> k;

        vector<int>weather(n);
      
        for(int i = 0; i < n; i++ ){
            cin >> weather[i];
         
        }

        
        int cnt = 0;
        int maxpeak = 0;

        int i = 0;
        

        while(i < n){
            if(weather[i] == 0){
                cnt++;
            }
            else{
                cnt = 0;
            }

            if(cnt == k){
                maxpeak++;
                cnt = 0;
                i += 2;
            }
            else{
                i++;
            }
        }
        cout << maxpeak << endl;
   
    }
}