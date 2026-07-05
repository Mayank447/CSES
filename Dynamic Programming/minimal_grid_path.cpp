#include <iostream>
#include <vector>
#include <string>
#include <deque>

// int main(){
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     int n;
//     std::cin >> n;

//     std::vector<std::string> grid(n);
//     for (int i=0; i<n; i++) std::cin >> grid[i];

//     // Main logic
//     std::vector<std::vector<char>> path(n, std::vector<char>(n));
//     path[n-1][n-1] = '.';

//     for (int i=0; i<n-1; i++){
//         path[n-1][i]='R';
//         path[i][n-1]='D';
//     }

//     for (int i=n-2; i>=0; i--){
//         for (int j=n-2; j>=0; j--)
//         {
//             int x1=i, y1 = j+1;
//             int x2=i+1, y2 = j;

//             std::string s1 {grid[x1][y1]};
//             std::string s2 {grid[x2][y2]};
            
//             while (s1 == s2 && (x1!=n-1 || y1!=n-1))
//             {
//                 if (path[x1][y1]=='D') x1 += 1;
//                 else y1 += 1;

//                 if (path[x2][y2]=='D') x2 += 1;
//                 else y2 += 1;

//                 s1 += grid[x1][y1];
//                 s2 += grid[x2][y2];
//             }

//             if (s1 < s2) path[i][j] = 'R';
//             else path[i][j] = 'D';
//         }
//     }

//     int i=0, j=0;
//     std::string lexographically_min_path {grid[i][j]};
//     while(i!=n-1 || j!=n-1){
//         if (path[i][j] == 'D') i+= 1;
//         else j+= 1;

//         lexographically_min_path += grid[i][j];
//     }

//     std::cout << lexographically_min_path << "\n";
//     return 0;
// }


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> grid(n);
    for (int i=0; i<n; i++) std::cin >> grid[i];
    
    // Main logic
    std::vector<std::vector<bool>> occupied(n, std::vector<bool>(n, false));
    std::deque<std::pair<int, int>> q;
    std::string path;

    q.push_back(std::make_pair(0,0));
    occupied[0][0] = true;
    path += grid[0][0];

    for (int i=0; i<2*n-2; i++){
        int m = q.size();
        auto it = q.begin();
        char min_char = 'Z';

        for (int k=0; k<m; k++){
            auto [r, c] = *it;
            if (r+1 < n){
                if (grid[r+1][c] < min_char) min_char = grid[r+1][c];
            }

            if (c+1 < n){
                if (grid[r][c+1] < min_char) min_char = grid[r][c+1];
            }
            it++;
        }
        path += min_char;

        for (int k=0; k<m; k++){
            auto [r, c] = q.front();
            if (r+1 < n){
                if (grid[r+1][c] == min_char && !occupied[r+1][c]){
                    q.push_back(std::make_pair(r+1, c));
                    occupied[r+1][c] = true;
                }
            }

            if (c+1 < n){
                if (grid[r][c+1] == min_char && !occupied[r][c+1]){
                    q.push_back(std::make_pair(r, c+1));
                    occupied[r][c+1] = true;
                }     
            }
            q.pop_front();
        }
    }

    std::cout << path << "\n";
    return 0;
}