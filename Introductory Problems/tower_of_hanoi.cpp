#include <iostream>
using namespace std;

int myPow(int x, unsigned int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;
  
  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}


int main(){
    int n;
    cin >> n;
    int A[n] = {0};

    int soln = myPow(2, n);
    cout << soln - 1 << endl;

    for (int i=1; i<soln; i++){
        // Finding the bit flip 0->1 in binary representation
        int num = i & ~(i-1);
        int digit = 0;
        while (num > 1) {
            num >>= 1;
            digit++;
        }
        
        if ((digit+n)%2 == 0){
            cout << A[digit]++ + 1;
            A[digit] %= 3;
            cout << " " << A[digit] + 1 << endl; 
        }

        else{
            cout << A[digit]-- + 1;
            A[digit] += 3;
            A[digit] %= 3;
            cout << " " << A[digit] + 1 << endl; 
        }
    } 
    return 0;
}