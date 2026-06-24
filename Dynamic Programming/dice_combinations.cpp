#include <iostream>
#include <vector>

#define MOD 1000000007

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Main logic
    std::vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=6; j++){
            if (i-j >= 0) {
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
            else break;
        }
    }

    std::cout << dp[n] << "\n";
    return 0;
}
