#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int X[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int n, x, y, dx, dy;

void move(vector<vector<int>> &A, int x, int y, queue<pair<int, int>> &S){
    for(int i=0; i<8; i++){
        dx = X[i];
        dy = Y[i];
        if ((x+dx > -1 && x+dx < n) && (y+dy > -1 && y+dy < n)){
            if (A[x+dx][y+dy] == -1 || A[x][y] < A[x+dx][y+dy] -1){
                A[x+dx][y+dy] = A[x][y] + 1;
                S.push(pair<int, int>(x+dx, y+dy));
            }
        }
    }
}

int main(){
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n, -1));
    A[0][0] = 0;
    
    queue<pair<int, int>> S;
    S.push(pair<int, int>(0, 0));

    while(!S.empty()){
        pair<int, int> p = S.front();
        S.pop();
        x = p.first;
        y = p.second;
        move(A, x, y, S);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}