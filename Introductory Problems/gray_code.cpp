#include <iostream>
#include <string>
using namespace std;

int myPow(int x, unsigned int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;
  
  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

string decimalToBinary(int num, int n) {
    string binary = "";
    for (int i = n - 1; i >= 0; i--) {
        binary += (num & (1 << i)) ? '1' : '0';
    }
    return binary;
}

int main(){
    int n, last, power, len;
    cin >> n;

    len = myPow(2, n);
    int A[len];
    A[0] = 0;
    A[1] = 1;

    for (int i=1; i<n; i++){
        power = myPow(2, i);
        last = power - 1;

        for (int j=0; j<power; j++){
            A[last + j+1] = power + A[last -j];
        }
    }

    for (int i=0; i<len; i++){
        cout << decimalToBinary(A[i], n) << endl;
    }
    return 0;
}