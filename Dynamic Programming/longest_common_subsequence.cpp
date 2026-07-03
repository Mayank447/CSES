#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> array1(n);
    std::vector<int> array2(m);

    for (int i=0; i<n; i++) std::cin >> array1[i];
    for (int i=0; i<m; i++) std::cin >> array2[i];

    // Main logic
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    if (array1[0] == array2[0]) dp[0][0] = 1;

    for (int i=1; i<n; i++){
        if (array1[i] == array2[0]) dp[i][0] = 1;
        else dp[i][0] = dp[i-1][0];
    }

    for (int j=1; j<m; j++){
        if (array1[0] == array2[j]) dp[0][j] = 1;
        else dp[0][j] = dp[0][j-1];
    }

    for (int i=1; i<n; i++){
        for (int j=1; j<m; j++){
            if (array1[i] == array2[j]) {
                dp[i][j] = std::max(1 + dp[i-1][j-1], std::max(dp[i-1][j], dp[i][j-1]));
            }
            else 
                dp[i][j] = std::max(dp[i-1][j-1], std::max(dp[i-1][j], dp[i][j-1]));
        }
    }

    int l = dp[n-1][m-1];
    std::cout << l << "\n";
    std::vector<int> path(l);

    int i = n-1, j = m-1;
    while (l > 0){
        if (i>0 && dp[i-1][j] == l) i--;
        else if (j>0 && dp[i][j-1] == l) j--;
        else if (i>0 && j>0 && dp[i-1][j-1] == l) {
            i--;
            j--;
        }
        else {
            path[--l] = array1[i];
            i--;
            j--;
        }
    }

    if (dp[n-1][m-1]){
        for (int i=0; i<path.size(); i++) std::cout << path[i] << " ";
        std::cout << "\n";
    }
    return 0;
}