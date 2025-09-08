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
        int n;
        cin >> n;

        vector<int> a(n);
        unordered_map<int , int> freq;
        for(int i =0 ; i < n; i++){
            cin >> a[i];
            freq[a[i]]++;

        }

       
        bool flag = false;

        for(auto it: freq){
            if(it.second == 1)
                flag = true;
        }

        if(flag){
            cout << "-1" << endl;
        }
        else{
            vector<int> student(n);
            for(int i= 0; i < n; i++){
                student[i] = i + 1;
            }

            int l = 0, r = 0;

            while(r < n){
                if(a[l] == a[r]) 
                    r++;
                else{
                    rotate(student.begin() + l , student.begin() + l    + 1 , student.begin() + r);
                    l = r;
                }
            }

            rotate(student.begin() + l , student.begin() + l + 1 ,  student.begin() + r);

            for(int i = 0; i < n; i++)
                cout << student[i] << " ";

            cout << endl;
        }
    }
}