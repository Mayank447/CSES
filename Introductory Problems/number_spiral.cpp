#include <iostream>
using namespace std;
 
long int max(long int a, long int b){
    if(a>b){
        return a;
    }
    return b;
}
 
 
int main(void){
    int t; 
    long int x, y, square, result;
    cin >> t;
 
    for(int i=0; i < t; i++){
        cin >> y >> x;
        square = max(x,y);
        result = (square - 1) * (square - 1);
 
        if (square % 2 == 0){
            result += y;
            result += square - x;
        }
 
        else {
            result += x;
            result += square - y;
        }
        cout << result << endl;
    }
 
    return 0;
