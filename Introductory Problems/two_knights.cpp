#include <iostream>
using namespace std;
 
long int cal_squares(int n){
    long int n_sq = n*n;
    return n_sq*(n_sq-1)/2 - 4*(n-2)*(n-1);
}
 
int main(){
    int n;
    cin >> n;
 
    int A[5] = {0, 6, 28, 96, 252};
    for (int i=0; i<n; i++){
        if (i < 5){
            cout << A[i] << endl;
        }
        else{
            cout << cal_squares(i+1) << endl;
        }
    }
