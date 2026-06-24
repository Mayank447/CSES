#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007
typedef long long ll;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> coins(n);
    for (int i=0; i<n; i++) {
        std::cin >> coins[i];
    }
    std::sort(coins.begin(), coins.end());

    // Main logic
    std::vector<ll> dp(x+1, 0);
    dp[0] = 1;

    for (int j=0; j<n; j++){
        for (int i=coins[0]; i<=x; i++){
            if (i - coins[j] >= 0){
                dp[i] += dp[i - coins[j]];
                dp[i] %= MOD;
            }
        }
    }

    std::cout << dp[x] << "\n";
    return 0;
}