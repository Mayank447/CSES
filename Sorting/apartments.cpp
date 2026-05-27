#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    int applicants[n];
    for (int i=0; i<n; i++) cin >> applicants[i];

    int apartments[m];
    for (int i=0; i<m; i++) cin >> apartments[i];
    
    sort(applicants, applicants + n);
    sort(apartments, apartments + m);

    int i=0, j=0;
    int assigned = 0;
    while(i != m && j != n){
        if ((apartments[i] >= applicants[j]-k) && (apartments[i] <= applicants[j]+k)){
            assigned++;
            i++;
            j++;
        }

        else if (apartments[i] < applicants[j]-k){
            i++;
        }

        else if (apartments[i] > applicants[j]+k){
            j++;
        }
    }

    cout << assigned << endl;
    return 0;
}