#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> grid(n);
    for (int i=0; i<n; i++) std::cin >> grid[i];

    // Main logic
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    if (grid[n-1][n-1] == '.') dp[n-1][n-1] = 1;

    for (int i=1; i<n; i++){
        // Only moving to the left (Columns)
        for (int j=n-1; j>n-i-1; j--){
            if (grid[n-i-1][j] == '*') continue;

            if (j+1 < n && grid[n-i-1][j+1]=='.'){
                dp[n-i-1][j] += dp[n-i-1][j+1];  // Right
                dp[n-i-1][j] %= MOD;
            }

            if (grid[n-i][j] == '.'){
                dp[n-i-1][j] += dp[n-i][j];  // Down
                dp[n-i-1][j] %= MOD;
            }
        }

        // Only moving down (Rows)
        for (int k=n-1; k>=n-i-1; k--){
            if (grid[k][n-i-1] == '*') continue;

            if (k+1 < n && grid[k+1][n-i-1]=='.'){
                dp[k][n-i-1] += dp[k+1][n-i-1]; // Down
                dp[k][n-i-1] %= MOD;
            }

            if (grid[k][n-i] == '.'){
                dp[k][n-i-1] += dp[k][n-i];  // Right
                dp[k][n-i-1] %= MOD;
            }
        }
    }

    // for (int i=0; i<n; i++){
    //     for (int j=0; j<n; j++){
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }

    std::cout << dp[0][0] << "\n";
    return 0;
}