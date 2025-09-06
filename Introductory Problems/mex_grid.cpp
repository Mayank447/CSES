#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;

    int A[n][n] = {-1};
    set<int> columns[n];
    set<int> rows[n];

    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int k = 0;
            while (true){
                if (rows[i].find(k) == rows[i].end() && columns[j].find(k) == columns[j].end()){
                    A[i][j] = k;
                    rows[i].insert(k);
                    columns[j].insert(k);
                    break;
                }
                k++;
            }
        }
    }

    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}