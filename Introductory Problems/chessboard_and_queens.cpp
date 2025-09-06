// #include <iostream>
// using namespace std;

// char A[8][8];
// bool flag = true;

// void printBoard(){
//     for(int i=0; i<8; i++){
//         for(int j=0; j<8; j++){
//             cout << A[i][j];
//         }
//         cout << endl;
//     }
// }

// void cross(int x, int y, char c1, char c2){
//     for (int i=0; i<8; i++){
//         if (A[x][i]==c1) A[x][i] = c2; // row
//         if (A[i][y]==c1) A[i][y] = c2; // column
//     }

//     for (int d=-7; d<=7; d++) {
//         if (0 <= x+d && x+d < 8 && 0 <= y+d && y+d < 8){
//             if (A[x+d][y+d] == c1) A[x+d][y+d] = c2;
//         }
        
//         if (0 <= x+d && x+d < 8 && 0 <= y-d && y-d < 8){
//             if (A[x+d][y-d] == c1) A[x+d][y-d] = c2;
//         }
//     }
// }

// int backtrack(int k){
//     if (k==0) {
//         return 1;
//     }
//     int ways = 0;

//     for(int i=0; i<8; i++){
//         for(int j=0; j<8; j++){
//             if(A[i][j] == '.'){
//                 cross(i, j, '.', 65+k);
//                 ways += backtrack(k-1);
//                 cross(i, j, 65+k, '.');
//             }
//         }
//     }
//     return ways;
// }

// int main(){
//     for (int i=0; i<8; i++){
//         for (int j=0; j<8; j++){
//             cin >> A[i][j];
//         }
//     }
    
//     cout << backtrack(8)/40320 << endl;
//     return 0;
// }


#include <iostream>
using namespace std;

// 8x8 board: '.' means free, '*' means blocked (occupied by other piece)
char A[8][8];

// occupancy trackers (one per column and two for the two diagonal families).
// These are global so they are zero-initialized (false) before main runs.
bool col[8], diag1[15], diag2[15];

int backtrack(int r) {
    // If we've processed all 8 rows, we've placed 8 queens successfully
    if (r == 8) return 1;

    int ways = 0;

    // Try placing a queen in row r at every column c
    for (int c = 0; c < 8; c++) {
        // Check three conditions:
        // 1) the cell itself is not blocked by '*' (must be '.'),
        // 2) the column c is free,
        // 3) both diagonals through (r,c) are free.
        if (A[r][c] == '.' && !col[c] && !diag1[r + c] && !diag2[r - c + 7]) {

            // Mark column and diagonals as occupied by this queen
            col[c] = diag1[r + c] = diag2[r - c + 7] = true;

            // Recurse to the next row; accumulate the number of valid completions
            ways += backtrack(r + 1);

            // Unmark (backtrack) so other choices in this row can be tried
            col[c] = diag1[r + c] = diag2[r - c + 7] = false;
        }
    }

    // Return how many valid configurations were found with rows r..7
    return ways;
}

int main() {
    // Read the 8x8 board from stdin (each A[i][j] gets one char)
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> A[i][j];

    // Start backtracking from row 0; print the total number of solutions
    cout << backtrack(0) << endl;
}