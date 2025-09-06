#include <iostream>
#include <string>
using namespace std;

string s;
int visited[7][7] = {0};

bool inside(int r, int c) {
    return r >= 0 && r < 7 && c >= 0 && c < 7;
}

int move(int r, int c, int step, char dir){
    if (r==6 && c==0){
        if (step == 48) return 1;
        else return 0;
    }
    
    if (step == 48) return 0;
    else if (r==0 && dir == 'U' && c>0 && c<6 && !visited[r][c-1] && !visited[r][c+1]) return 0;
    else if (r==6 && dir == 'D' && c>0 && c<6 && !visited[r][c-1] && !visited[r][c+1]) return 0;
    else if (c==0 && dir == 'L' && r>0 && r<6 && !visited[r-1][c] && !visited[r+1][c]) return 0;
    else if (c==6 && dir == 'R' && r>0 && r<6 && !visited[r-1][c] && !visited[r+1][c]) return 0;
    else if (dir == 'L' && c>0 && visited[r][c-1]){
        if(r>0 && r<6 && !visited[r-1][c] && !visited[r+1][c]) return 0;
    }
    else if (dir == 'R' && c<6 && visited[r][c+1]){
        if(r>0 && r<6 && !visited[r-1][c] && !visited[r+1][c]) return 0;
    }
    else if (dir == 'D' && r<6 && visited[r+1][c]) {
        if(c>0 && c<6 && !visited[r][c-1] && !visited[r][c+1]) return 0;
    }
    else if (dir == 'U' && r>0 && visited[r-1][c]) {
        if(c>0 && c<6 && !visited[r][c-1] && !visited[r][c+1]) return 0;
    }
    
    int ways = 0;
    visited[r][c] = true;

    if (inside(r, c-1) && !visited[r][c-1]){
        if (dir != 'R' && (s[step]=='?' || s[step]=='L')) ways += move(r, c-1, step+1, 'L');
    } 

    if (inside(r, c+1)  && !visited[r][c+1]) {
        if (dir != 'L' && (s[step]=='?' || s[step]=='R')) ways += move(r, c+1, step+1, 'R');
    }

    if (inside(r-1, c) && !visited[r-1][c]) {
        if (dir != 'D' && (s[step]=='?' || s[step]=='U')) ways += move(r-1, c, step+1, 'U');
    }

    if (inside(r+1, c) && !visited[r+1][c]) {
        if (dir != 'U' && (s[step]=='?' || s[step]=='D')) ways += move(r+1, c, step+1, 'D');
    }

    visited[r][c] = false;
    return ways;
}

int main(){
    cin >> s;
    cout << move(0,0,0,'A') << endl;
    return 0;
}