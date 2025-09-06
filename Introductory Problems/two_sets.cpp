#include <iostream>
using namespace std;

int main(){
    long int n;
    cin >> n;

    if (n==1 | (n*(n+1)/2) % 2 == 1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

    if (n%2 == 0){
        cout << n/2 << endl;
        for (int i=1; i<n/2;){
            cout << i << " " << n-i+1 << " ";
            i += 2;
        }
        
        cout << endl << n/2 << endl;
        for (int i=2; i<=n/2;){
            cout << i << " " << n-i+1 << " ";
            i += 2;
        }
    }

    else {
        cout << (n-1)/2 + 1 << endl;
        cout << 1 << " " << 2 << " ";
        for (int i=0; i < (n-3)/2;){
            cout << i+4 << " " << n-i << " ";
            i += 2;
        }

        cout << endl << (n-1)/2 << endl;
        cout << 3 << " ";
        for (int i=1; i<=(n-3)/2;){
            cout << i+4 << " " << n-i << " ";
            i += 2;
        }
    }
    return 0;
}