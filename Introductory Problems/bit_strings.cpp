#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long int result = 1;
    for (int i=0; i<n; i++){
        result *= 2;
        result %= 1000000007;
    }
    cout << result << endl;
    return 0;
}