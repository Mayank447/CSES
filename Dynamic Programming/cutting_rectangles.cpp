#include <iostream>
#include <vector>
#define MAX 1000000000

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b;
    std::cin >> a >> b;

    // Main logic
    std::vector<std::vector<int>> dp(a+1, std::vector<int>(b+1, 0));

    for (int j=2; j<=b; j++){
        int min = MAX;
        for (int k=1; k<j; k++) min = std::min(min, dp[1][k] + dp[1][j-k]);
        dp[1][j] = 1 + min;
    }

    for (int i=2; i<=a; i++){
        int min = MAX;
        for (int k=1; k<i; k++) min = std::min(min, dp[k][1] + dp[i-k][1]);
        dp[i][1] = 1 + min;
    }

    for (int i=2; i<=a; i++){
        for (int j=2; j<=b; j++){
            if (i==j) continue;
            int min = MAX;
            for (int k=1; k<i; k++) min = std::min(min, dp[i-k][j] + dp[k][j]);
            for (int k=1; k<j; k++) min = std::min(min, dp[i][k] + dp[i][j-k]);
            dp[i][j] = 1 + min;
        }
    }

    std::cout << dp[a][b] << "\n";
    return 0;
}