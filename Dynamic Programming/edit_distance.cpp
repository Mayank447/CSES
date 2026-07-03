#include <iostream>
#include <string>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s1, s2;
    std::cin >> s1;
    std::cin >> s2;

    int n = s1.size();
    int m = s2.size();

    // Inserting, deleting, replacing in B is symmetric to Deleting, inserting, replacing in A
    // So we can only modify string A instead;
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
    for (int j=1; j<=m; j++) dp[0][j] = j;
    for (int i=1; i<=n; i++) dp[i][0] = i;
 
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s1[i-1] != s2[j-1])
                dp[i][j] = 1 + std::min(dp[i-1][j], std::min(dp[i][j-1], dp[i-1][j-1]));
            else
                dp[i][j] = dp[i-1][j-1];
        }
    }

    std::cout << dp[n][m] << "\n";
    return 0;
}

