#include <iostream>
using namespace std;

int main(){
    int t, n, a, b;
    cin >> t;

    for (int i=0; i<t; i++){
        cin >> n >> a >> b;
        
        if ((a + b > n) || (a+b!=0 && (a==0 || b==0))){
            cout << "NO" << endl;
            continue;
        }

        int A[n], B[n] = {0};
        
        for (int i=1; i<a; i++){
            A[i-1] = i+1;
            B[i-1] = i;
        }

        A[a-1] = a+b; B[a-1] = a;
        A[a] = 1; B[a] = a+1;

        for (int j=a+2; j<a+b+1; j++){
            A[j-1] = j-1;
            B[j-1] = j;
        }

        // Same
        for(int i=a+b; i<n; i++){
            A[i] = i+1;
            B[i] = i+1;
        }

        cout << "YES" << endl;

        for(int i=0; i<n; i++) cout << A[i] << " ";
        cout << endl;
        for(int i=0; i<n; i++) cout << B[i] << " ";
        cout << endl;
    }
    return 0;
}