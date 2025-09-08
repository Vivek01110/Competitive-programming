#include<iostream>
using namespace std;
int insertNintoM(int M , int N,int i , int j){
    int allOnes = ~0; 

    int left = allOnes << (j + 1);   
    int right = (1 << i) - 1;        

    int mask = left | right;         

   
    int M_cleared = M & mask;

    
    int N_shifted = N << i;

  
    return M_cleared | N_shifted;
}
int main(){
    int T;
    cin>> T;

    while(T--){
        int n, m;
        cin >> n >> m;

        int i , j;
        cin >> i >> j;

       cout << insertNintoM(m , n, i, j);



    }
}