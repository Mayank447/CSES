#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;

    int A[n];
    for (int i=0; i<n; i++) cin >> A[i];

    int m = 0;
    set<int> unique;
    for (int i=0; i<n; i++){
        if (unique.find(A[i]) == unique.end()){
            unique.insert(A[i]);
            m++;
        }
    }
    
    cout << m << endl;
    return 0;
}