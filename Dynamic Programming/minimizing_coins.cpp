#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000001

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> coins(n);
    for (int i=0; i<n; i++) std::cin >> coins[i];
    std::sort(coins.begin(), coins.end());

    // Main logic
    std::vector<int> dp(x+1, MAX);
    dp[0] = 0;

    for (int i=1; i<=x; i++){
        for (int j=0; j<n; j++){
            if (i - coins[j] >= 0)
                dp[i] = std::min(dp[i - coins[j]] + 1, dp[i]);  
            else break;
        }
    }

    if (dp[x] == MAX) dp[x] = -1;
    std::cout << dp[x] << "\n";
    return 0;
}