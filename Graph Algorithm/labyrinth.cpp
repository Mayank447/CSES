#include <bits/stdc++.h>
using namespace std;

int n, m;
int start_x, start_y;
int end_x, end_y;

string construct_path(vector<vector<char>> &direction){
    string s;
    int x = end_x;
    int y = end_y;
    while(x != start_x || y != start_y){
        char move = direction[x][y];
        s += move;

        if (move == 'D') x--;
        else if (move == 'U') x++;
        else if (move == 'R') y--;
        else if (move == 'L') y++;
    }
 
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<string> A(n);
    vector<vector<char>> direction(n, vector<char>(m,'E'));
    
    for (int i=0; i<n; i++){
        cin >> A[i];
        for (int j=0; j<m; j++){
            if (A[i][j]=='A'){
                start_x = i;
                start_y = j;
            }
            else if (A[i][j]=='B'){
                end_x = i;
                end_y = j;
            }
        }
    }

    queue<pair<int, int>> bfs;
    direction[start_x][start_y] = 'S';
    bfs.push(pair<int, int>(start_x, start_y));
    
    while (!bfs.empty()){
        int i = bfs.front().first;
        int j = bfs.front().second;
        bfs.pop();
        
        if (A[i][j]=='B') {
            cout << "YES" << endl;
            string s = construct_path(direction);
            cout << s.length() << endl;
            cout << s << endl;
            return 0;
        }
        if (i+1 < n && A[i+1][j]!='#' && direction[i+1][j]=='E') {
            bfs.push(pair<int, int> (i+1, j));
            direction[i+1][j] = 'D';
        }
        if (j+1 < m && A[i][j+1]!='#' && direction[i][j+1]=='E') {
            bfs.push(pair<int, int> (i, j+1));
            direction[i][j+1] = 'R';
        }
        if (i > 0 && A[i-1][j]!='#' && direction[i-1][j]=='E') {
            bfs.push(pair<int, int> (i-1, j));
            direction[i-1][j] = 'U';
        }
        if (j > 0 && A[i][j-1]!='#' && direction[i][j-1]=='E') {
            bfs.push(pair<int, int>(i, j-1));
            direction[i][j-1] = 'L';
        }
    }
    cout << "NO" << endl;
    return 0;
}