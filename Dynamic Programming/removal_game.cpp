#include <iostream>
#include <vector>

typedef long long ll;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> array(n);
    for (int i=0; i<n; i++) std::cin >> array[i];

    // Main logic
    std::vector<std::vector<std::pair<ll, ll>>> dp(n, std::vector<std::pair<ll, ll>>(n, std::make_pair(0,0)));
    for (int i=0; i<n; i++) {
        dp[i][i].first = array[i];
        dp[i][i].second = 0;
    }

    for (int j=1; j<n; j++){
        for (int i=0; i<n-1; i++) {
            if (i+j<n) {
                if (array[i+j] + dp[i][i+j-1].second > array[i] + dp[i+1][i+j].second){
                    dp[i][i+j].first = array[i+j] + dp[i][i+j-1].second;
                    dp[i][i+j].second = dp[i][i+j-1].first;
                }
                else {
                    dp[i][i+j].first = array[i] + dp[i+1][i+j].second;
                    dp[i][i+j].second = dp[i+1][i+j].first;
                }
            }
            else break;
        }
    }

    std::cout << dp[0][n-1].first << "\n";
    return 0;
}