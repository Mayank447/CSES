#include <iostream>
using namespace std;
 
int main(void){
    int n; 
    cin >> n;
 
    if(n < 4 && n>1){
        cout << "NO SOLUTION" << endl;
    }
 
    else
    {
        int lower = (int)n/2;
        for(int i=0; i < lower; i++){
            cout << (2*(i+1)) << " ";
        }
 
        for(int i=0; i < (n-lower); i++){
            cout << (2*i + 1) << " ";
        }
    }
 
    return 0;
}