#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

  

   
        int n;
        cin >> n;

        string s;
        cin >> s;
        if(n == 1) cout << "NO" << endl;
        else{
              int index = -1;
              for(int i = 0; i < n - 1; i++){
                  if(s[i] > s[i + 1]){
                     index = i;
                     break;
                  }
              }

              if(index == -1){
                 cout << "NO" << endl;
              }
              else{
                  cout << "YES" << endl;
                  cout << index  + 1 <<" "<< index + 2 << endl;
              }
        }


      
    
}