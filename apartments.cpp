#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    int A[n];
    for (int i=0; i<n; i++) cin >> A[i];

    int B[m], occupied[m] = {0};
    for (int i=0; i<m; i++) cin >> B[i];

    sort(B, B + m);

    for (int i=0; i<n; i++){
        int l = lower_bound(B, B+m, A[i]-k);
        int r = upperbound(B, B+m, A[i]+k);

        if(l == r && !occupied[l]) occupied[l] = 1;
    }
    return 0;
}