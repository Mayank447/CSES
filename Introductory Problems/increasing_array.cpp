#include <iostream>
using namespace std;
 
int main(void){
    int n;
    cin >> n;
 
    int A[n];
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
 
    long int moves = 0;
    int max = A[0];
 
    for(int i=1; i<n; i++){
        if(A[i] <= max){
            moves += (max - A[i]);
        }
 
        else{
            max = A[i];
        }
    }
 
    cout << moves << endl;
    return 0;
