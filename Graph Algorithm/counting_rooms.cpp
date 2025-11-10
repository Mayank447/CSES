#include <bits/stdc++.h>
using namespace std;

int n, m;

int recurse(int i, int j, vector<vector<char>> &A, vector<vector<bool>> &covered) {
    if (i < 0 || j < 0 || i >= n || j >= m) return 0;
    if (A[i][j] != '.' || covered[i][j]) return 0;

    covered[i][j] = true;
    if (i+1 < n) recurse(i+1, j, A, covered);
    if (j+1 < m) recurse(i, j+1, A, covered);
    if (i > 0) recurse(i-1, j, A, covered);
    if (j > 0) recurse(i, j-1, A, covered);
    return 1;
}

int main(){
    cin >> n >> m;
    vector<vector<char>> A(n, vector<char>(m));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> covered(n, vector<bool>(m, false));
    int num_rooms = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            num_rooms += recurse(i, j, A, covered);
        }
    }
    cout << num_rooms << endl;
    return 0;
}