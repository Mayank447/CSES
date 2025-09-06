#include <iostream>
using namespace std;
 
int main(void){
    int n, num;
    cin >> n;
 
    int A[n];
    for (int i=0; i < n; i++)
        A[i] = 0;
 
    for (int i=0; i<(n-1); i++){
        cin >> num;
        A[num-1] = 1;
    }
 
    for (int i=0; i < n; i++){
        if (A[i]==0){
            cout << (i+1);
            break;
        }
    }
 
    return 0;
}