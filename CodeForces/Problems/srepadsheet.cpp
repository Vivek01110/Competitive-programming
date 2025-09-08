#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        string s;
        cin>> s;

        int n = s.size();
        string row;
        string col;

        if(s[0] == 'R' && (s[1] >= '0' && s[1] <= '9')){
            // cout << "ia m in first" << endl;
            
            // to collect row number
            int i = 1;
            while(i < n && s[i] != 'C')
                row.push_back(s[i++]);

            // cout << "row" << row << endl;
            i++;

            int colnum = 0;
            while(i < n){
                colnum = colnum*10 + (s[i++] - '0');
            }
            
            // cout << "colnum" << colnum << endl;
            while(colnum !=  0){
                // cout << "colnum" << colnum << endl;
                // cout << "col " << col << endl;
                colnum--;
                col.push_back((colnum%26) + 'A');
                 
                colnum /= 26;
                
            };

            // cout << "col " << col << endl;

            reverse(col.begin() , col.end());

            // cout << "col " << col << endl;

            col += row;

            cout << col << endl;
        }
        else{
            // cout << "ia m in second" << endl;
            
            int i = 0;

            while(i < n && s[i] >= 'A' && s[i] <= 'Z'){
                col.push_back(s[i++]);
            }


         

            while(i < n){
                row.push_back(s[i++]);
            }

            int j = col.size() - 1;

            int colnum = 0;
            int itr = 0;

            while(j >= 0){
                colnum += (pow(26 , itr++)*(((col[j]) - 'A') + 1));
                
                j--;
            }

            col = "";

            while(colnum){
                col.push_back(colnum%10 + '0');
                colnum /= 10;
            }

            reverse(col.begin() , col.end());

            cout << "R" << row << "C" << col << endl;





       
        }

        

    }
}

//tESTCASES
/*
8
A1
BC23
R23C55
R230C827
RZ228
R228C494
AEU230
R853C18

*/