#include <iostream>
#include <vector>
using namespace std;

// Try backtracking
char characters[4] = {'A', 'B', 'C', 'D'};
int n, m;

int move(vector<vector<char>> &A, int i, int j){
    if (i==n) return 1;

    char c = A[i][j];
    for (int k=0; k<4; k++){
        if (characters[k] == A[i][j]) continue;
        if (j>0 && characters[k] == A[i][j-1]) continue;
        if (i>0 && characters[k] == A[i-1][j]) continue;
        A[i][j] = characters[k]; 

        if (j<m-1 && move(A, i, j+1)) return 1;
        else if (move(A, i+1, 0)) return 1;
        A[i][j] = c;
    }
    return 0;
}

int main(){
    cin >> n >> m;

    vector<vector<char>> A(n, vector<char> (m));
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }
    
    if (!move(A, 0, 0)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << A[i][j];
        }
        cout << endl;
    }

    return 0;
}