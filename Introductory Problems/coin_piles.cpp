#include <iostream>
using namespace std;

int main(){
    int t, a, b, temp;
    cin >> t;

    for (int i=0; i<t; i++){
        cin >> a >> b;
        if (b > a){
            temp = a;
            a = b;
            b = temp;
        }

        temp = a-b;
        b -= temp;
        a -= 2*temp;

        if (b % 3 == 0 && b > -1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}