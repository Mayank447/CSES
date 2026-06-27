#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;

    std::vector<std::pair<int, int>> books(n); // price, pages
    for (int i=0; i<n; i++) std::cin >> books[i].first;
    for (int i=0; i<n; i++) std::cin >> books[i].second;

    // Main logic
    // This is a knapsack problem
    std::vector<int> dp(x+1, 0);
    dp[0] = 0;

    for (int i=0; i<n; i++){
        for (int j = x; j >= books[i].first; j--) {
            dp[j] = std::max(dp[j], dp[j - books[i].first] + books[i].second);
        }
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}