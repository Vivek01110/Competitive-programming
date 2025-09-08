#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n , target_sum;
        cin >> n >> target_sum;

       
        int sum = 0;
        vector<int>cnt(3);
        for(int i= 0; i < n; i++){
            int temp;
            cin >> temp;
             sum += temp;

            cnt[temp]++;
        }

       

        //  to prevent alice reaching her target_sum , we can separate 0 and 1 , because with adjecent 0 , 1 alice can make any target by repaeating 0 , 1;

        //  Also alice can make any target sum using (0, 2) and (2 , 1)
        // like  using 2, 3 we can make any number except 1 

        //   1 cannot be make using (0,1) or (2,1) like , it can not  be made using 2 , 3, so we can prevent only then;

         if(target_sum <  sum || (target_sum - sum) == 1){    
             while(cnt[0]--) cout << "0 ";
             while(cnt[2]--) cout << "2 ";
             while(cnt[1]--) cout << "1 ";
             cout << endl;
         }
         else{
            cout << "-1" << endl;
         }
    }
}
