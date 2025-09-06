#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;

// Convert __int128 to string
string to_string128(i128 x) {
    if (x == 0) return "0";
    string s;
    while (x > 0) {
        s.push_back('0' + (x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

__int128 myPow(int x, unsigned int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;
  
  __int128 tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

int digit(i128 k) {
    int num_digits = 1;
    __int128 sum = 9;

    while(true){
        if(k < sum){
            break;
        }
        sum += 9 * myPow(10, num_digits) * (num_digits+1);
        num_digits++;
    }

    k -= (sum - 9*num_digits*myPow(10, num_digits-1));
    __int128 offset = k/num_digits;

    __int128 number = myPow(10, num_digits-1) + offset;
    string s = to_string128(number);
    
    int digit_required = k%num_digits;
    return s[digit_required] - '0';
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        long long k;   
        cin >> k;
        cout << digit((i128)(k-1)) << "\n";
    }
}