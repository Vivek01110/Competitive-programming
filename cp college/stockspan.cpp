#include<iostream>
#include<stack>
#include<vector>
using namespace std;
 
 void stock_span(vector<int> arr , int n){
    if(n == 0)
        cout << 0;
        
    stack<int> st;
    vector<int> stspan;
    

    for(int i = 0; i < n; i++){     
           
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }

            if(st.empty()){
                stspan.push_back(i + 1);
            }
            else{
                stspan.push_back(i - st.top());
            }
            

            st.push(i);

        }
//the  under the under the under the 
        for(int i= 0; i < n; i++){
            cout << stspan[i] << " ";
        }
        cout << endl;
    }
    

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        stack<int> st;
        vector<int> arr(n);
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        stock_span(arr, n);

       
    }
}

// 3 
// 7
// 100 80 60 70 60 75 85
// 5
// 1 2 3 3 4
// 0







